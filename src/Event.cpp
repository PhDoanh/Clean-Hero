#include "Sound.hpp"
#include "Event.hpp"
#include "Entity.hpp"

void Event::handleKeyboard()
{
	switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LALT:
			SDL_StopTextInput();
			player->speed = Vec2D(6);
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LALT:
			SDL_StartTextInput();
			player->speed = Vec2D(0);
			break;
		default:
			break;
		}

	case SDL_TEXTINPUT:
		cur_txt_inp += e.text.text;
		break;
	case SDL_TEXTEDITING:
		break;
	}
}

void Event::handleMouse()
{
	switch (e.type)
	{
	case SDL_MOUSEMOTION:
		mouse_pos = Vec2D(e.motion.x, e.motion.y);
		break;
	case SDL_MOUSEBUTTONDOWN:
		switch (e.button.button)
		{
		case SDL_BUTTON_LEFT:
			sound->playSoundEffect("lclick", general);
			break;
		case SDL_BUTTON_RIGHT:
			sound->playSoundEffect("rclick", general);
			break;
		default:
			break;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		break;
	default:
		break;
	}
}