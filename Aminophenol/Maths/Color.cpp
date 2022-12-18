
#include "pch.h"
#include "Color.h"

#include "Utils.h"

namespace Aminophenol::Maths
{

	// Empty constructor
	Color::Color()
		: r(0.0f)
		, g(0.0f)
		, b(0.0f)
		, a(0.0f)
	{}

	// Single value constructor
	Color::Color(float value)
	{
		// Handle the out of range
		value = Maths::clamp(value, 0.0f, 1.0f);

		// Set the values
		r = value;
		g = value;
		b = value;
		a = 1.0f;
	}

	// Individual component constructor with a color format
	Color::Color(float xValue, float yValue, float zValue, float wValue, ColorFormat format)
	{
		// Handle the out of range
		xValue = Maths::clamp(xValue, 0.0f, 1.0f);
		yValue = Maths::clamp(yValue, 0.0f, 1.0f);
		zValue = Maths::clamp(zValue, 0.0f, 1.0f);
		wValue = Maths::clamp(wValue, 0.0f, 1.0f);

		switch (format)
		{
		case ColorFormat::RGB:
			r = xValue;
			g = yValue;
			b = zValue;
			a = 1.0f;
			break;
		case ColorFormat::RGBA:
			r = xValue;
			g = yValue;
			b = zValue;
			a = wValue;
			break;
		case ColorFormat::ARGB:
			r = yValue;
			g = zValue;
			b = wValue;
			a = xValue;
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Constructor from a Vector3
	Color::Color(Vector3<float> vector, float alpha, ColorFormat format)
	{
		// Handle the out of range
		vector.x = Maths::clamp(vector.x, 0.0f, 1.0f);
		vector.y = Maths::clamp(vector.y, 0.0f, 1.0f);
		vector.z = Maths::clamp(vector.z, 0.0f, 1.0f);
		alpha = Maths::clamp(alpha, 0.0f, 1.0f);
		
		switch (format)
		{
		case ColorFormat::RGB:
			r = vector.x;
			g = vector.y;
			b = vector.z;
			a = 1.0f;
			break;
		case ColorFormat::RGBA:
		case ColorFormat::ARGB:
			r = vector.x;
			g = vector.y;
			b = vector.z;
			a = alpha;
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Constructor from a Vector4
	Color::Color(Vector4<float> vector, ColorFormat format)
	{
		// Handle the out of range
		vector.x = Maths::clamp(vector.x, 0.0f, 1.0f);
		vector.y = Maths::clamp(vector.y, 0.0f, 1.0f);
		vector.z = Maths::clamp(vector.z, 0.0f, 1.0f);
		vector.w = Maths::clamp(vector.w, 0.0f, 1.0f);
		
		switch (format)
		{
		case ColorFormat::RGB:
			r = vector.x;
			g = vector.y;
			b = vector.z;
			a = 1.0f;
			break;
		case ColorFormat::RGBA:
			r = vector.x;
			g = vector.y;
			b = vector.z;
			a = vector.w;
			break;
		case ColorFormat::ARGB:
			r = vector.y;
			g = vector.z;
			b = vector.w;
			a = vector.x;
			break;
		}
	}
	
	// Constructor from a 32 bits unsigned integer and a color format
	Color::Color(uint32_t value, ColorFormat format)
	{
		switch (format)
		{
		case ColorFormat::RGB:
			r = static_cast<float>((uint8_t)(value >> 16)) / 255.0f;
			g = static_cast<float>((uint8_t)(value >> 8)) / 255.0f;
			b = static_cast<float>((uint8_t)(value & 0xFF)) / 255.0f;
			a = 1.0f;
			break;
		case ColorFormat::RGBA:
			r = static_cast<float>((uint8_t)(value >> 24)) / 255.0f;
			g = static_cast<float>((uint8_t)(value >> 16)) / 255.0f;
			b = static_cast<float>((uint8_t)(value >> 8)) / 255.0f;
			a = static_cast<float>((uint8_t)(value & 0xFF)) / 255.0f;
			break;
		case ColorFormat::ARGB:
			r = static_cast<float>((uint8_t)(value >> 16)) / 255.0f;
			g = static_cast<float>((uint8_t)(value >> 8)) / 255.0f;
			b = static_cast<float>((uint8_t)(value & 0xFF)) / 255.0f;
			a = static_cast<float>((uint8_t)(value >> 24)) / 255.0f;
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Copy constructor
	Color::Color(const Color& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	// Assignment operator
	Color& Color::operator=(const Color& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	// Move assignment operator
	Color& Color::operator=(Color&& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	// Static method to interpolate between two colors
	Color Color::lerp(Color color1, Color color2, float amount)
	{
		return Color(
			Maths::lerp(color1.r, color2.r, amount),
			Maths::lerp(color1.g, color2.g, amount),
			Maths::lerp(color1.b, color2.b, amount),
			Maths::lerp(color1.a, color2.a, amount)
		);
	}

	// Getter as a 32 bits unsigned integer
	uint32_t Color::toInt32(ColorFormat format) const
	{
		switch (format)
		{
		case ColorFormat::RGB:
			return (static_cast<uint8_t>(r * 255.0f) << 16) | (static_cast<uint8_t>(g * 255.0f) << 8) | (static_cast<uint8_t>(b * 255.0f));
			break;
		case ColorFormat::RGBA:
			return (static_cast<uint8_t>(r * 255.0f) << 24) | (static_cast<uint8_t>(g * 255.0f) << 16) | (static_cast<uint8_t>(b * 255.0f) << 8) | (static_cast<uint8_t>(a * 255.0f));
			break;
		case ColorFormat::ARGB:
			return (static_cast<uint8_t>(a * 255.0f) << 24) | (static_cast<uint8_t>(r * 255.0f) << 16) | (static_cast<uint8_t>(g * 255.0f) << 8) | (static_cast<uint8_t>(b * 255.0f));
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Getter as hex string
	std::string Color::toHexString(ColorFormat format) const
	{
		switch (format)
		{
		case ColorFormat::RGB:
		{
			std::stringstream stream;
			stream << "#";
			uint32_t hex = ((static_cast<uint32_t>(r * 255.0f) & 0xFF) << 16) + ((static_cast<uint32_t>(g * 255.0f) & 0xFF) << 8) + ((static_cast<uint32_t>(b * 255.0f) & 0xFF) << 0);
			stream << std::hex << std::setw(6) << std::setfill('0') << hex;
			return stream.str();
			break;
		}
		case ColorFormat::RGBA:
		{
			std::stringstream stream;
			stream << "#";
			uint32_t hex = ((static_cast<uint32_t>(r * 255.0f) & 0xFF) << 24) + ((static_cast<uint32_t>(g * 255.0f) & 0xFF) << 16) + ((static_cast<uint32_t>(b * 255.0f) & 0xFF) << 8) + ((static_cast<uint32_t>(a * 255.0f) & 0xFF) << 0);
			stream << std::hex << std::setw(6) << std::setfill('0') << hex;
			return stream.str();
			break;
		}
		case ColorFormat::ARGB:
			throw std::exception("Color::toHexString: ARGB format is not supported");
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}
	
	// Getter as a Vector3
	Vector3<float> Color::toVector3(ColorFormat format) const
	{
		switch (format)
		{
		case ColorFormat::RGB:
			return Vector3<float>(r, g, b);
			break;
		case ColorFormat::ARGB:
			throw std::exception("Not implemented");
			break;
		case ColorFormat::RGBA:
			throw std::exception("Not implemented");
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Getter as a Vector4
	Vector4<float> Color::toVector4(ColorFormat format) const
	{
		switch (format)
		{
		case ColorFormat::RGB:
			throw std::exception("Not implemented");
			break;
		case ColorFormat::ARGB:
			return Vector4<float>(a, r, g, b);
			break;
		case ColorFormat::RGBA:
			return Vector4<float>(r, g, b, a);
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Getter as an array of floats
	float* Color::toArray(ColorFormat format) const
	{
		switch (format)
		{
		case ColorFormat::RGB:
			return new float[3] { r, g, b };
			break;
		case ColorFormat::ARGB:
			return new float[4] { a, r, g, b };
			break;
		case ColorFormat::RGBA:
			return new float[4] { r, g, b, a };
			break;
		default:
			throw std::exception("Invalid color format");
			break;
		}
	}

	// Addition method
	Color& Color::add(const Color& other)
	{
		r = Maths::clamp(r + other.r, 0.0f, 1.0f);
		g = Maths::clamp(g + other.g, 0.0f, 1.0f);
		b = Maths::clamp(b + other.b, 0.0f, 1.0f);
		return *this;
	}

	// Subtraction method
	Color& Color::subtract(const Color& other)
	{
		r = Maths::clamp(r - other.r, 0.0f, 1.0f);
		g = Maths::clamp(g - other.g, 0.0f, 1.0f);
		b = Maths::clamp(b - other.b, 0.0f, 1.0f);
		return *this;
	}

	// Multiplication method
	Color& Color::multiply(const Color& other)
	{
		r = Maths::clamp(r * other.r, 0.0f, 1.0f);
		g = Maths::clamp(g * other.g, 0.0f, 1.0f);
		b = Maths::clamp(b * other.b, 0.0f, 1.0f);
		return *this;
	}
	
	// Multiplication method with a scalar
	Color& Color::multiply(float scalar)
	{
		r = Maths::clamp(r * scalar, 0.0f, 1.0f);
		g = Maths::clamp(g * scalar, 0.0f, 1.0f);
		b = Maths::clamp(b * scalar, 0.0f, 1.0f);
		return *this;
	}
	
	// Division method
	Color& Color::divide(const Color& other)
	{
		if (other.r == 0.0f || other.g == 0.0f || other.b == 0.0f)
			throw std::exception("Cannot divide by zero");

		r = Maths::clamp(r / other.r, 0.0f, 1.0f);
		g = Maths::clamp(g / other.g, 0.0f, 1.0f);
		b = Maths::clamp(b / other.b, 0.0f, 1.0f);
		return *this;
	}

	// Division method with a scalar
	Color& Color::divide(float scalar)
	{
		if (scalar == 0.0f)
			throw std::exception("Cannot divide by zero");
		
		r = Maths::clamp(r / scalar, 0.0f, 1.0f);
		g = Maths::clamp(g / scalar, 0.0f, 1.0f);
		b = Maths::clamp(b / scalar, 0.0f, 1.0f);
		return *this;
	}

	// Addition operator
	Color Color::operator+(const Color& other) const
	{
		Color result = *this;
		result.add(other);
		return result;
	}
	
	// Subtraction operator
	Color Color::operator-(const Color& other) const
	{
		Color result = *this;
		result.subtract(other);
		return result;
	}
	
	// Multiplication operator
	Color Color::operator*(const Color& other) const
	{
		Color result = *this;
		result.multiply(other);
		return result;
	}
	
	// Multiplication operator with a scalar
	Color Color::operator*(float scalar) const
	{
		Color result = *this;
		result.multiply(scalar);
		return result;
	}

	// Division operator
	Color Color::operator/(const Color& other) const
	{
		Color result = *this;
		result.divide(other);
		return result;
	}

	// Division operator with a scalar
	Color Color::operator/(float scalar) const
	{
		Color result = *this;
		result.divide(scalar);
		return result;
	}

	// Addition assignment operator
	Color& Color::operator+=(const Color& other)
	{
		return add(other);
	}
	
	// Subtraction assignment operator
	Color& Color::operator-=(const Color& other)
	{
		return subtract(other);
	}
	
	// Multiplication assignment operator
	Color& Color::operator*=(const Color& other)
	{
		return multiply(other);
	}
	
	// Multiplication assignment operator with a scalar
	Color& Color::operator*=(float scalar)
	{
		return multiply(scalar);
	}

	// Division assignment operator
	Color& Color::operator/=(const Color& other)
	{
		return divide(other);
	}
	
	// Division assignment operator with a scalar
	Color& Color::operator/=(float scalar)
	{
		return divide(scalar);
	}

	// Equality operator
	bool Color::operator==(const Color& other) const
	{
		return (r == other.r && g == other.g && b == other.b && a == other.a);
	}

	// Inequality operator
	bool Color::operator!=(const Color& other) const
	{
		return (r != other.r || g != other.g || b != other.b || a != other.a);
	}

	// Output stream operator
	std::ostream& operator<<(std::ostream& stream, const Color& color)
	{
		stream << "Color(" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")";
		return stream;
	}
	
}
