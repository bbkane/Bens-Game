#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <cassert>

//TODO:
//Questions about scaling. How will I scale an object?
// How should I set the scale? 

class Texture 
{
public:
	Texture()
	{
		texture = nullptr;
		scale.x = 0;
		scale.y = 0;
		scale.w = 0;
		scale.h = 0;
	}
	
	~Texture() = default;

	bool init(SDL_Renderer * renderer, std::string image_path, int x1, int y1, int x2, int y2)
	{
		this->renderer = renderer;
		SDL_Surface * bmp = SDL_LoadBMP(image_path.c_str());
		this->texture = SDL_CreateTextureFromSurface(renderer, bmp);
		SDL_FreeSurface(bmp);
		scale.x = x1;
		scale.y = y1;
		scale.w = x2 - x1;
		scale.h = y2 - y1;
	
		return true;
	}

	bool init(SDL_Renderer * renderer, std::string image_path)
	{
		this->renderer = renderer;
		SDL_Surface * bmp = SDL_LoadBMP(image_path.c_str());
		assert(bmp != NULL && "BMP not loaded");
		this->texture = SDL_CreateTextureFromSurface(renderer, bmp);
		assert(texture != NULL && "texture not created");
		SDL_FreeSurface(bmp);
		scale.x = 0;
		scale.y = 0;
		scale.w = 100;
		scale.h = 100;

		return true;
	}

	bool destroy()
	{
		SDL_DestroyTexture(texture);
		return true;
	}

	void draw()
	{
		SDL_RenderCopy(renderer, texture, NULL, &scale);
	}

	bool is_valid() const
	{
		return valid;
	}

private:
	SDL_Renderer * renderer;
	SDL_Rect scale;
	SDL_Texture * texture;
	bool valid{ true };
};

