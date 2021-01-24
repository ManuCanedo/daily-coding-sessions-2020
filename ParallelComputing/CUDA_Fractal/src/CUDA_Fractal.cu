#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "Bitmap.h"

#include <cstdint>
#include <math.h>
#include <string>
#include <iostream>

// Kernel executed at the Device
__global__ void fractalKernel(uint8_t* dev_a, const unsigned width, const unsigned height, const unsigned iterations)
{
	const int x = threadIdx.x + blockIdx.x * blockDim.x;
    const int y = threadIdx.y + blockIdx.y * blockDim.y;

    if ((x + y * width) < width * height)
    {
        double cr = x * 0.02 / width - 0.65;
        double ci = y * 0.02 / height - 0.4;
        double zr = 0.0, zi = 0.0;
        double re = 0.0, im = 0.0;

        int n = 0;
        while ((zr * zr + zi * zi) < 4.0 && n < iterations)
        {
            re = zr * zr - zi * zi + cr;
            im = zr * zi * 2.0 + ci;
            zr = re;
            zi = im;
            n++;
        }

        dev_a[3 * (x + y * width) + 0] = uint8_t(255 * (0.5f * sin(0.1f * n) + 0.5f));
        dev_a[3 * (x + y * width) + 1] = uint8_t(255 * (0.2f * sin(0.1f * n + 2.094f) + 0.5f));
        dev_a[3 * (x + y * width) + 2] = uint8_t(255 * (0.5f * sin(0.1f * n + 4.188f) + 0.5f));
    }
}

cudaError_t calculateWithCuda(uint8_t* hst_a, const unsigned width, const unsigned height, const unsigned iterations)
{
    unsigned size = width * height * 3;
    dim3 blocks(128,72), threads(32,30);
    uint8_t *dev_a = nullptr;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

    // Allocate GPU buffer    .
    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(uint8_t));
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vectors from host memory to GPU buffer.
    cudaStatus = cudaMemcpy(dev_a, hst_a, size * sizeof(uint8_t), cudaMemcpyHostToDevice);
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    //// Get Device Properties
    cudaDeviceProp props;
    cudaStatus = cudaGetDeviceProperties(&props, 0);
    if (cudaStatus != cudaSuccess)
    {
        fprintf(stderr, "cudaGetDeviceProperties failed!");
        goto Error;
    }
    std::cout << "GPU: " << props.name << ", maxThreadsPerBlock: " << props.maxThreadsPerBlock << std::endl;

    // Launch a kernel on the GPU with one thread for each element.
    fractalKernel <<< blocks, threads >>> (dev_a, width, height, iterations);
    
    // Check for any errors launching the kernel
    cudaStatus = cudaGetLastError();
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
        goto Error;
    }
    
    // cudaDeviceSynchronize waits for the kernel to finish, and returns
    // any errors encountered during the launch.
    cudaStatus = cudaDeviceSynchronize();
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }

    // Copy output vector from GPU buffer to host memory.
    cudaStatus = cudaMemcpy(hst_a, dev_a, size * sizeof(uint8_t), cudaMemcpyDeviceToHost);
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
    cudaFree(dev_a);
    
    return cudaStatus;
}

int main()
{
    const unsigned width = 4096, height = 2160, arraySize = { width * height * 3 };
	const unsigned iterations = 1024;
	uint8_t* hst_x = new uint8_t[arraySize]{ 0 };

    // Generate Fractal using CUDA
	cudaError_t cudaStatus = calculateWithCuda(hst_x, width, height, iterations);
	if (cudaStatus != cudaSuccess) 
	{
        fprintf(stderr, "calculateWithCuda failed!");
        return 1;
	}

	// Save Fractal to a bitmap file
	Bitmap::SaveFractal(hst_x, width, height);
	
	return 0;
}