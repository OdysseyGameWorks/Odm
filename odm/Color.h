#pragma once

/*
 Author - Odyssey.
 Specially developed maths library of game development.
 Heavily commented for the user to be able to understand easily.
 */

#ifndef _COLOR_H_
#define _COLOR_H_

#include <string>
#include "Vector4f.h"

namespace odm
{
	constexpr auto OneOver255 = (1.0f / 255.0f);
	
	struct Color
	{
		float r; 
		float g; 
		float b; 
		float a;

		/**
		 * Constructs a color.
		 * Sets all rgb elements to 0.
		 */
		Color();


		/**
		 * Constructs a color by copying from the other color object.
		 * @param color Object to copy the values from.
		 */
		Color(const Color& color) = default;


		/**
		 * Constructs a color setting the value of rgba.
		 * @param rf Sets the Red component.
		 * @param gf Sets the Green component.
		 * @param bf Sets the Blue component.
		 * @param af Sets the Alpha component.
		 */
		explicit Color(float rf, float gf, float bf, float af = 1.0f);

		
		/**
		 * Constructs a color by copying values from vector4.
		 * @param vector Vector4 to copy the values of rgba channels.
		 */
		explicit Color(const Vector4f& vector);


		/**
		 * Constructs a color by copying values from vector3.
		 * Alpha value is by default set to 1.0f.
		 * @param vector Vector3 to copy the values of rgb channels.
		 */
		explicit Color(const Vector3f& vector);


		/** Destructor */
		~Color() = default;

		/**
		 * Checks the equality of two color values.
		 * @param c The color to compare with.
		 * @returns True if the compared color is equal.
		*/
		inline bool operator==(const Color& c) const;

		/**
		 * Checks the non-equality of two color values.
		 * @param c The color to compare with.
		 * @returns True if the compared color is not equal.
		*/
		bool operator!=(const Color& c) const;

		/**
		 * Sets the color between 0 to 1.
		 * @param c Takes the color to be converted to lower scale.
		 * @returns RGBA color between the range of 0 to 1. 
		 */
		static Color to8bit(const Color& c);
		static Color toSmallerScale(float r, float g, float b, float a);
		
		static std::string Stringify(const Color& c);


		static const Color White;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Magenta;
		static const Color Cyan;
		static const Color Yellow;
		static const Color Black;
		static const Color Aquamarine;
		static const Color BakerChocolate;
		static const Color BlueViolet;
		static const Color Brass;
		static const Color BrightGold;
		static const Color Brown;
		static const Color Bronze;
		static const Color BronzeII;
		static const Color CadetBlue;
		static const Color CoolCopper;
		static const Color Copper;
		static const Color Coral;
		static const Color CornFlowerBlue;
		static const Color DarkBrown;
		static const Color DarkGreen;
		static const Color DarkGreenCopper;
		static const Color DarkOliveGreen;
		static const Color DarkOrchid;
		static const Color DarkPurple;
		static const Color DarkSlateBlue;
		static const Color DarkSlateGrey;
		static const Color DarkTan;
		static const Color DarkTurquoise;
		static const Color DarkWood;
		static const Color DimGrey;
		static const Color DustyRose;
		static const Color Feldspar;
		static const Color Firebrick;
		static const Color ForestGreen;
		static const Color Gold;
		static const Color Goldenrod;
		static const Color Grey;
		static const Color GreenCopper;
		static const Color GreenYellow;
		static const Color HunterGreen;
		static const Color IndianRed;
		static const Color Khaki;
		static const Color LightBlue;
		static const Color LightGrey;
		static const Color LightSteelBlue;
		static const Color LightWood;
		static const Color LimeGreen;
		static const Color MandarianOrange;
		static const Color Maroon;
		static const Color MediumAquamarine;
		static const Color MediumBlue;
		static const Color MediumForestGreen;
		static const Color MediumGoldenrod;
		static const Color MediumOrchid;
		static const Color MediumSeaGreen;
		static const Color MediumSlateBlue;
		static const Color MediumSpringGreen;
		static const Color MediumTurquoise;
		static const Color MediumVioletRed;
		static const Color MediumWood;
		static const Color MidnightBlue;
		static const Color NavyBlue;
		static const Color NeonBlue;
		static const Color NeonPink;
		static const Color NewMidnightBlue;
		static const Color NewTan;
		static const Color OldGold;
		static const Color Orange;
		static const Color OrangeRed;
		static const Color Orchid;
		static const Color PaleGreen;
		static const Color Pink;
		static const Color Plum;
		static const Color Quartz;
		static const Color RichBlue;
		static const Color Salmon;
		static const Color Scarlet;
		static const Color SeaGreen;
		static const Color SemiSweetChocolate;
		static const Color Sienna;
		static const Color Silver;
		static const Color SkyBlue;
		static const Color SlateBlue;
		static const Color SpicyPink;
		static const Color SpringGreen;
		static const Color SteelBlue;
		static const Color SummerSky;
		static const Color Tan;
		static const Color Thistle;
		static const Color Turquoise;
		static const Color VeryDarkBrown;
		static const Color VeryLightGrey;
		static const Color Violet;
		static const Color VioletRed;
		static const Color Wheat;
		static const Color YellowGreen;
	};

	inline Color::Color() {
		r = g = b = 0.0f, a = 1.0f;
	}

	inline Color::Color(float rf, float gf, float bf, float af)
		: r(rf), g(gf), b(bf), a(af)
	{}

	inline Color::Color(const Vector4f& vector)
		: r(vector.x), g(vector.y), b(vector.z), a(vector.w)
	{}

	inline Color::Color(const Vector3f& vector)
		: r(vector.x), g(vector.y), b(vector.z), a(1.0f)
	{}

	inline bool Color::operator==(const Color & c) const
	{
		return (r == c.r && g == c.g && b == c.b && a == c.a);
	}

	inline bool Color::operator!=(const Color& c) const
	{
		return !(r == c.r && g == c.g && b == c.b && a == c.a);
	}

	inline Color Color::to8bit(const Color& c)
	{
		return Color(c.r * OneOver255, c.g * OneOver255, c.b * OneOver255, c.a * OneOver255);
	}

	inline Color Color::toSmallerScale(float r, float g, float b, float a)
	{
		return Color(r * OneOver255, g * OneOver255, b * OneOver255, a * OneOver255);
	}

	inline std::string Color::Stringify(const Color& c)
	{
		
	}

	
}

#else
#error Color header had already been include. 
#endif
