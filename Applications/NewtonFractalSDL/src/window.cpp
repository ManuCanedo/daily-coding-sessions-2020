#include "window.hpp"

#include <unordered_map>
#include <iostream>


/*
 *	Math utilities
 */
constexpr int ROUND_POS = 3;

constexpr double truncate(double value)
{
	/*
	 *	Truncate
	 */
	const int factor = std::pow(10, ROUND_POS + 1);
	return std::ceil(value * factor) / factor;
}

constexpr int unique(double lhs, double rhs)
{
	/*
	 *	Cantor's pairing function
	 */
	const int ulhs = std::round(lhs * ROUND_POS);
	const int urhs = std::round(rhs * ROUND_POS);
	return urhs + (ulhs + urhs) * (ulhs + urhs + 1) / 2;
};

struct DoublePair {
	constexpr DoublePair(double x = 0.0, double y = 0.0) : x(x), y(y)
	{
	}
	double x;
	double y;
};


/*
 *	Window class
 */
Window::Window(int N, int delay) : m_side(N), m_delay(delay)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	m_window = SDL_CreateWindow(
		"Newton's Fractal",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		m_side,
		m_side,
		SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

void Window::render()
{
	clear();
	render_fractal();
	display();
}

void Window::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
}

void Window::render_fractal()
{
	static constexpr int max_iters = 100;
	static constexpr double tolerance = 0.00001;
	static std::unordered_map<unsigned int, std::complex<double> > roots;

	const int N = m_side;
	int i, j, k;
	std::complex<double> x;

	for (j = 0; j != N; ++j) {
		for (i = 0; i != N; ++i) {
			x = { -2.0 + 4.0 * i / N, -2.0 + 4.0 * j / N };
			for (k = 0; k < max_iters; k++) {
				const std::complex<double> p_res = p(x);
				if (std::abs(p_res) < tolerance)
					break;

				x = x - p_res / dp(x);
			}
			if (k != max_iters) {
				const double real_round = truncate(x.real());
				const double imag_round = truncate(x.imag());
				SDL_SetRenderDrawColor(
					m_renderer,
					int(sin(real_round + 1) * 255),
					int(sin(imag_round + 0.1) * 255),
					int(sin(real_round * imag_round + 0.2) *
					    255),
					255);
				SDL_RenderDrawPoint(m_renderer, i, j);
				roots.insert({ unique(real_round, imag_round),
					       { real_round, imag_round } });
			}
		}
	}
	std::cout << "Detected " << roots.size() << " roots!\n";
}

void Window::display()
{
	SDL_RenderPresent(m_renderer);
	SDL_Delay(m_delay);
}


/*
 *	Main
 */
int main(int argv, char** args)
{
	Window window(900, 10000);
	window.render();

	return 0;
}
