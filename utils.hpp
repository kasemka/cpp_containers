#ifndef UTILS_HPP
#define UTILS_HPP


namespace ft
{
	// is_integral<char>::value  == true
	// is_integral<char>::value  == false

	template <class T, bool v>
	struct integral_constant 
	{
		static const bool value = v;
		typedef bool value_type;
		typedef integral_constant<T,v> type;
		operator value_type(){ 
			return v; }
	};


	typedef ft::integral_constant<bool,true>	true_type;
	typedef ft::integral_constant<bool,false>	false_type;

	template <class> struct is_integral							: public false_type {};	//primary template
	template <> struct is_integral <bool>						: public true_type {};	//explicit template specialization
	template <> struct is_integral <char>						: public true_type {};
	// template <> struct is_integral <char16_t>					: public true_type {};
	// template <> struct is_integral <char32_t>					: public true_type {};
	template <> struct is_integral <wchar_t>					: public true_type {};
	template <> struct is_integral <signed char>				: public true_type {};
	template <> struct is_integral <short int>					: public true_type {};
	template <> struct is_integral <int>						: public true_type {};
	template <> struct is_integral <long int>					: public true_type {};
	template <> struct is_integral <long long int>				: public true_type {};
	template <> struct is_integral <unsigned char>				: public true_type {};
	template <> struct is_integral <unsigned short int>			: public true_type {};
	template <> struct is_integral <unsigned int>				: public true_type {};
	template <> struct is_integral <unsigned long int>			: public true_type {};
	template <> struct is_integral <unsigned long long int>		: public true_type {};


	template<bool Cond, class T = void> struct enable_if {}; 			//primary template
	template<class T> struct enable_if<true, T> { typedef T type; }; 	//explicit template specialization


	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		for (; first1 != last1; ++first1, (void) ++first2)
		{
			if (!pred(*first1, *first2))
				return false;
		}
		return true;
	};

	template <class T1, class T2> struct pair
	{

	};

}

#endif