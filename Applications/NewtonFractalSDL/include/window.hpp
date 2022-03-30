#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <complex>
#include <cmath>

#include "SDL.h"

class Window {
public:
	Window(int N, int delay);

	void render();

private:
	void clear();
	void render_fractal();
	void display();

	std::complex<double> p(const std::complex<double>& z) const;
	std::complex<double> dp(const std::complex<double>& z) const;

	int m_side;
	int m_delay;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

inline std::complex<double> Window::p(const std::complex<double>& x) const
{
	return std::pow(x, 5) + std::pow(x, 2) - x +
	       std::complex<double>{ 1.0, 0.0 };
}

inline std::complex<double> Window::dp(const std::complex<double>& x) const
{
	return 5.0 * std::pow(x, 4) + 2.0 * x - std::complex<double>{ 1.0, 0.0 };
}
#endif
