#include "Button.h"
#include "raylib.h"

Button::Button()
{
	m_title = "";
	m_rectangle = { 10, 10, 100, 25 };
	m_callback = {};
	m_draw = NULL;
	m_hover = {};
}

Button::Button(std::string title, Rectangle rectangle, Color colour)
{
	m_title = title;
	m_rectangle = rectangle;
	m_callback = {};
	m_draw = NULL;
	m_hover = {};
	col = colour;
}

void Button::OnClick(std::function<void()> callback)
{
	m_callback = callback;
}

void Button::OnDraw(std::function<void(Rectangle rectangle)> callback)
{
	m_draw = callback;
}

void Button::OnHover(std::function<void(Rectangle rectangle)> callback)
{
	m_hover = callback;
}

void Button::Click()
{
	m_callback();
}

Button::~Button()
{
}

void Button::Update()
{
	Vector2 mousePos = GetMousePosition();

	// Check in box code.
	m_hovering = (
		(mousePos.x >= m_rectangle.x)
		&&
		(mousePos.x <= (m_rectangle.x + m_rectangle.width))
		&&
		(mousePos.y >= m_rectangle.y)
		&&
		(mousePos.y <= (m_rectangle.y + m_rectangle.height))
	);

	m_clicking = (m_hovering && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));

	if (m_clicking)
	{
		Click();
	}
}

void Button::BaseDraw()
{
	DrawRectangleRec(m_rectangle, col);

	int fontSize = m_rectangle.height / m_title.length();
	int center = m_title.length() / 1.5;
	center *= fontSize / 2;

	// This is center alignment.
	DrawText(m_title.c_str(), (m_rectangle.x + m_rectangle.width / 2) - center, m_rectangle.y + m_rectangle.height / 2 - fontSize / 2, fontSize, BLACK);
}

void Button::Draw()
{
	if (m_draw == NULL)
	{
		BaseDraw();
	}
	else m_draw(m_rectangle);

	if (m_hovering) m_hover(m_rectangle);
}
