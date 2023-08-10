
#ifndef NON_COPYABLE_H
#define NON_COPYABLE_H

namespace Aminophenol {

	class NonCopyable
	{

	protected:
		NonCopyable() = default;
		virtual ~NonCopyable() = default;

	public:
		NonCopyable(const NonCopyable&) = delete;
		NonCopyable(NonCopyable&&) noexcept = default;
		NonCopyable& operator=(const NonCopyable&) = delete;
		NonCopyable& operator=(NonCopyable&&) noexcept = default;

	};

} // namespace Aminophenol

#endif // !NON_COPYABLE_H
