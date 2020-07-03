#pragma once
#include <string>
#include <iostream>
#include "raylib.h"
#include <functional>

class Button
{
	public:
		Button();
		Button(std::string title, Rectangle rectangle, Color colour);
		
		void OnClick(std::function<void()> callback);
		void OnDraw(std::function<void(Rectangle rectangle)> callback);
		void OnHover(std::function<void(Rectangle rectangle)> callback);

		void Click();
		
		virtual ~Button();

		virtual void Update();
		
		virtual void BaseDraw();
		virtual void Draw();
		
		Color col = WHITE;
	private:
		std::string m_title;
		Rectangle m_rectangle;
		std::function<void()> m_callback;
		std::function<void(Rectangle rectangle)> m_draw;
		std::function<void(Rectangle rectangle)> m_hover;

		bool m_clicking = false;
		bool m_hovering = false;
};