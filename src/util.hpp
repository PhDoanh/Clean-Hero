#include <iostream>
#include <string>
#include <cmath>
#include "../inc/SDL.h"

#ifndef UTIL_HPP
#define UTIL_HPP

const double PI = 3.1415926536;

struct Vec2D;

// backend analysis
inline void log(const std::string &msg) { std::clog << "  log| " << msg; }
inline void info(const std::string &msg) { std::cout << " info| " << msg; }
inline void error(const std::string &msg)
{
	std::cerr << "error| " << msg;
	exit(1);
}
void drawLine(const Vec2D &, const Vec2D &, const SDL_Color &color = {255, 255, 255, 255});
void drawRect(const Vec2D &, const Vec2D &, const SDL_Color &color = {255, 255, 255, 255});

// interpolation
inline float lerp(float goal, float cur, float dt)
{
	float diff = goal - cur;
	if (diff > dt)
		return cur + dt;
	if (diff < -dt)
		return cur - dt;
	return goal;
}

inline double lerpAngle(double start, double end, double amount)
{
	double diff = abs(end - start);
	if (diff > 180)
	{
		if (end > start)
			start += 360;
		else
			end += 360;
	}
	float value = (start + ((end - start) * amount));
	float rangeZero = 360;
	if (value >= 0 && value <= 360)
		return value;
	return fmod(value, rangeZero);
}

// manage all objects time
struct Time
{
	Uint64 time;
	Uint64 last_time;
};

// manage 2d objects more easily
struct Vec2D
{
	float x, y;
	Vec2D() : x(0.0), y(0.0) {}
	Vec2D(float val) : x(val), y(val) {}
	Vec2D(float x, float y) : x(x), y(y) {}

	float distance(const Vec2D &v);
	bool between(const Vec2D &v1, const Vec2D &v2);
};

std::ostream &operator<<(std::ostream &out, const Vec2D &v);
Vec2D operator+(const Vec2D &v1, const Vec2D &v2);
Vec2D operator-(const Vec2D &v1, const Vec2D &v2);
Vec2D operator*(const Vec2D &v, float k);
Vec2D operator/(const Vec2D &v, float k);
Vec2D operator-(const Vec2D &v);
void operator+=(Vec2D &v1, const Vec2D &v2);
void operator-=(Vec2D &v1, const Vec2D &v2);
void operator*=(Vec2D &v, float k);
void operator/=(Vec2D &v, float k);
Vec2D max(const Vec2D &v1, const Vec2D &v2);
Vec2D min(const Vec2D &v1, const Vec2D &v2);
Vec2D toInt(const Vec2D &v);

// control objects direction
struct Direction
{
	float left, right, up, down;
	Direction() : left(0), right(0), up(0), down(0) {}
	Direction(float l, float r, float u, float d) : left(l), right(r), up(u), down(d) {}
};

// list of basic colors
struct Color
{
	static SDL_Color white(Uint8 alpha) { return {255, 255, 255, alpha}; }
	static SDL_Color black(Uint8 alpha) { return {0, 0, 0, alpha}; }
	static SDL_Color blue(Uint8 alpha) { return {0, 0, 255, alpha}; }
	static SDL_Color red(Uint8 alpha) { return {255, 0, 0, alpha}; }
	static SDL_Color green(Uint8 alpha) { return {0, 255, 0, alpha}; }
	static SDL_Color violet(Uint8 alpha) { return {238, 130, 238, alpha}; }
	static SDL_Color pink(Uint8 alpha) { return {255, 192, 203, alpha}; }
	static SDL_Color yellow(Uint8 alpha) { return {255, 255, 0, alpha}; }
	static SDL_Color light_orange(Uint8 alpha) { return {252, 156, 89, alpha}; }
	static SDL_Color cyan(Uint8 alpha) { return {0, 255, 255, alpha}; }
	static SDL_Color ice_blue(Uint8 alpha) { return {234, 237, 240, alpha}; }
	static SDL_Color blue_gray(Uint8 alpha) { return {129, 146, 168, alpha}; }
};

// my functions for rectangles
struct Rect
{
	static SDL_FRect square(float size) { return {0, 0, size, size}; }
	static bool isCollide(const Vec2D &v1pos, const Vec2D &v1size, const Vec2D &v2pos, const Vec2D &v2size);
	static Uint32 get_pixel(SDL_Surface *, const int &, const int &);
	static bool isPixelCollide(SDL_Texture *, SDL_Rect, SDL_Texture *, SDL_Rect);
	static Vec2D getCenter(const Vec2D &pos, const Vec2D &size);
	static SDL_FRect reScale(const Vec2D &pos, const Vec2D &size, float scale);
};

#endif // UTIL_HPP