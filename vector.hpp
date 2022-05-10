#ifndef VECTOR_HPP
#define VECTOR_HPP


// #include <vector>




namespace ft
{

	template<typename vector>
	class vectorIter
	{
		private:
		PointerType m_Ptr;

		public:
		using ValueType = typename Vector::ValueType;
		using PointerType = ValueType *;
		using ReferenceType = ValueType &;
		public:
		vectorIter(PointerType PTRDIFF_MAX){
			: mPtr(ptr);
		};
		vectorIter &operator++()
		{
			mPtr++;
			return *this;
		}
		vectorIter operator++(int)
		{
			vectorIter iterator = *this;
			++(*this);
			return iterator;
		}
		vectorIter &operator--()
		{
			mPtr--;
			return *this;
		}
		vectorIter operator--(int)
		{
			vectorIter iterator = *this;
			--(*this);
			return iterator;
		}
		ReferenceType operator[](int index)
		{
			return *(mPtr[index]);
		}
		ReferenceType operator->()
		{
			return mPtr;
		}
		ReferenceType operator*()
		{
			return *mPtr;
		}
		bool operator==(const vectorIter &other) const
		{
			return mPtr == other.mPtr;
		}
		bool operator!=(const vectorIter &other) const
		{
			return !(*this == other);
		}
	};


	template<typename T>
	class vector
	{
		private:
		T* mData = nullptr;
		size_t mSize=0;
		size_t mCapacity=0;
		public:
		using ValuseType = T;
		using Iterator = vectorIter<vector<T>>;

		public:
		vector(){
			//allocate 2 elems
			// ReAlloc(2);
		};
		~vector(){
			Clear();
			::operator delete(mData, mCapacity *sizeof(T));
		}
		void PushBack(const T &value)
		{
			if (mSize >= mCapacity)
				ReAlloc(mCapacity + mCapacity /2);
			mData[mSize] = value;
			mSize++;
		}
		void PushBack(T &&value)
		{
			if (mSize >= mCapacity)
				ReAlloc(mCapacity + mCapacity /2);
			mData[mSize] = std::move(value);
			mSize++;
		}
		size_t Size() const {
			return mSize;
		}
		Iterator begin()
		{
			return Iterator(mData);	
		}
		Iterator end()
		{
			return Iterator(mData + mSize);	
		}
	};
}


#endif


// push_back(value): This method appends the data to the vector.
// pop_back(): This method removes the last element from the vector.
// insert(index, value): This method inserts new elements before the element at the specified position.
// size(): This method returns the size of the vector.
// empty(): This method checks whether the vector is empty or not.
// front(): This method returns the first value of the vector.
// back(): The back method returns the last value of the vector.
// at(index): This method returns the value at the specified position.
// erase(index): The erase method removes elements from the given index.
// clear(): This method clears all the items in the vector.
// begin(): It returns an iterator element which points to the first element of the vector.
// end(): It returns an iterator element which points to the last element of the vector.
// swap(): Swaps the two input vectors.




