
#ifndef COLOR_H
#define COLOR_H

#include "Vector3.h"
#include "Vector4.h"

namespace Aminophenol::Maths
{

	// Color format enum
	enum class ColorFormat
	{
		RGB,
		RGBA,
		ARGB,
	};

	class Color
	{
	public:

		/// <summary>
		/// Empty constructor.
		/// </summary>
		Color();

		/// <summary>
		/// Single value constructor.
		/// </summary>
		/// <param name="value">The value</param>
		Color(float value);

		/// <summary>
		/// Individual component constructor with a color format.
		/// </summary>
		/// <param name="r">Red component</param>
		/// <param name="g">Green component</param>
		/// <param name="b">Blue component</param>
		/// <param name="a">Alpha component</param>
		/// <param name="format">Color format</param>
		Color(float r, float g, float b, float a = 1.0f, ColorFormat format = ColorFormat::RGBA);

		/// <summary>
		/// Constructor from a Vector3.
		/// </summary>
		/// <param name="v">The vector.</param>
		/// <param name="a">Alpha component</param>
		/// <param name="format">Color format</param>
		Color(Vector3<float> vector, float alpha = 1.0f, ColorFormat format = ColorFormat::RGBA);
		
		/// <summary>
		/// Constructor from a Vector4.
		/// </summary>
		/// <param name="v">The vector.</param>
		Color(Vector4<float> vector, ColorFormat format = ColorFormat::RGBA);
		
		/// <summary>
		/// Constructor from a 32 bits unsigned integer and a color format.
		/// </summary>
		/// <param name="value">32 bits value</param>
		/// <param name="format">Color format</param>
		Color(uint32_t value, ColorFormat format = ColorFormat::RGBA);

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="color">The color to copy</param>
		Color(const Color& color);

		/// <summary>
		/// Assignment operator.
		/// </summary>
		/// <param name="color">The color to copy</param>
		/// <returns>The color</returns>
		Color& operator=(const Color& color);

		/// <summary>
		/// Move assignment operator.
		/// </summary>
		/// <param name="color">The color to move</param>
		/// <returns>The color</returns>
		Color& operator=(Color&& color);

		/// <summary>
		/// Static method to interpolate between two colors.
		/// </summary>
		/// <param name="color0">First color</param>
		/// <param name="color1">Second color</param>
		/// <param name="t">Interpolation factor</param>
		/// <returns>Interpolated color</returns>
		static Color lerp(Color color0, Color color1, float amount);

		/// <summary>
		/// Getter as a 32 bits unsigned integer.
		/// </summary>
		/// <param name="format">Color format</param>
		/// <returns>32 bits value</returns>
		uint32_t toInt32(ColorFormat format = ColorFormat::RGBA) const;

		/// <summary>
		/// Getter as hex string.
		/// </summary>
		/// <param name="format">Color format</param>
		/// <returns>Hex string</returns>
		std::string toHexString(ColorFormat format = ColorFormat::RGB) const;

		/// <summary>
		/// Getter as a Vector3.
		/// </summary>
		/// <returns>Vector3</returns>
		Vector3<float> toVector3(ColorFormat format = ColorFormat::RGB) const;

		/// <summary>
		/// Getter as a Vector4.
		/// </summary>
		/// <returns>Vector4</returns>
		Vector4<float> toVector4(ColorFormat format = ColorFormat::RGBA) const;
		
		/// <summary>
		/// Getter as an array of floats.
		/// </summary>
		/// <returns>Array of floats</returns>
		float* toArray(ColorFormat format = ColorFormat::RGBA) const;

		/// <summary>
		/// Addition method.
		/// </summary>
		/// <param name="color">The color to add</param>
		/// <returns>The color</returns>
		Color& add(const Color& other);

		/// <summary>
		/// Subtraction method.
		/// </summary>
		/// <param name="color">The color to subtract</param>
		/// <returns>The color</returns>
		Color& subtract(const Color& other);

		/// <summary>
		/// Multiplication method.
		/// </summary>
		/// <param name="color">The color to multiply</param>
		/// <returns>The color</returns>
		Color& multiply(const Color& other);

		/// <summary>
		/// Multiplication method with a scalar.
		/// </summary>
		/// <param name="scalar">The scalar to multiply</param>
		/// <returns>The color</returns>
		Color& multiply(float scalar);

		/// <summary>
		/// Division method.
		/// </summary>
		/// <param name="color">The color to divide</param>
		/// <returns>The color</returns>
		Color& divide(const Color& other);

		/// <summary>
		/// Division method with a scalar.
		/// </summary>
		/// <param name="scalar">The scalar to divide</param>
		/// <returns>The color</returns>
		Color& divide(float scalar);

		/// <summary>
		/// Addition operator.
		/// </summary>
		/// <param name="color">The color to add</param>
		/// <returns>The color</returns>
		Color operator+(const Color& other) const;

		/// <summary>
		/// Subtraction operator.
		/// </summary>
		/// <param name="color">The color to subtract</param>
		/// <returns>The color</returns>
		Color operator-(const Color& other) const;

		/// <summary>
		/// Multiplication operator.
		/// </summary>
		/// <param name="color">The color to multiply</param>
		/// <returns>The color</returns>
		Color operator*(const Color& other) const;

		/// <summary>
		/// Multiplication operator with a scalar.
		/// </summary>
		/// <param name="scalar">The scalar to multiply</param>
		/// <returns>The color</returns>
		Color operator*(float scalar) const;
		
		/// <summary>
		/// Division operator.
		/// </summary>
		/// <param name="color">The color to divide</param>
		/// <returns>The color</returns>
		Color operator/(const Color& other) const;

		/// <summary>
		/// Division operator with a scalar.
		/// </summary>
		/// <param name="scalar">The scalar to divide</param>
		/// <returns>The color</returns>
		Color operator/(float scalar) const;

		/// <summary>
		/// Addition assignment operator.
		/// </summary>
		/// <param name="color">The color to add</param>
		/// <returns>The color</returns>
		Color& operator+=(const Color& other);
		
		/// <summary>
		/// Subtraction assignment operator.
		/// </summary>
		/// <param name="color">The color to subtract</param>
		/// <returns>The color</returns>
		Color& operator-=(const Color& other);
		
		/// <summary>
		/// Multiplication assignment operator.
		/// </summary>
		/// <param name="color">The color to multiply</param>
		/// <returns>The color</returns>
		Color& operator*=(const Color& other);

		/// <summary>
		/// Multiplication assignment operator with a scalar.
		/// </summary>
		/// <param name="scalar">The scalar to multiply</param>
		///	<returns>The color</returns>
		Color& operator*=(float scalar);
		
		/// <summary>
		/// Division assignment operator.
		/// </summary>
		/// <param name="color">The color to divide</param>
		/// <returns>The color</returns>
		Color& operator/=(const Color& other);

		/// <summary>
		/// Division assignment operator with a scalar.
		/// </summary>
		/// <param name="scalar">The scalar to divide</param>
		/// <returns>The color</returns>
		Color& operator/=(float scalar);

		/// <summary>
		/// Equality operator.
		/// </summary>
		/// <param name="color">The color to compare</param>
		bool operator==(const Color& other) const;

		/// <summary>
		/// Inequality operator.
		/// </summary>
		/// <param name="color">The color to compare</param>
		bool operator!=(const Color& other) const;

		/// <summary>
		/// Output stream operator.
		/// </summary>
		/// <param name="os">Output stream</param>
		/// <param name="color">Color</param>
		friend std::ostream& operator<<(std::ostream& os, const Color& color);

		float r{ 0.0f };
		float g{ 0.0f };
		float b{ 0.0f };
		float a{ 1.0f };

	private:

		// Nothing here

	};

}
#endif // COLOR_H
