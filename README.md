# String class similar to std::string

## Key points | Thoughts for the design of tlib::tstring
### 1. Rule of big three (and a half)
If we have to manage resources like char pointer in this lib - we need to create our own copy constructor, destructor and an assignment operator. For assignment operator we need a swap function (that's why three and a half).
Details:   
https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three)

### 2. Swap Function:
There are various ways of writing the swap function (even std::vector has criticism for it's swap function before c++ 14)
Read more about Argument Dependent Look-up(ADL) for the friend function choice of swap
Other things to keep in mind:  
a. self-assignment should work (can't deleted the given reference and having if to check is wasting the computation time for most of the cases)     
b. Swap is a non-throwing function  
c. For a strong exception guarantee we need to copy the string before deleting it (because creating a new string can result in an exception)  
d. This required extra memory and rather than allocating the memory inside the function we let the compiler do it by passing it as the value  

Details:  
Copy and swap idiom (https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom)  
ADL (https://stackoverflow.com/questions/8111677/what-is-argument-dependent-lookup-aka-adl-or-koenig-lookup)
### 3. Reset and alloc_str:
Reset and alloc_str functions are used by a lot of other functions. Do not repeat yourself (DRY)

### 4. Do not add - operator const char * () const;  
Adding this operator though is convenient for the printing tstring with cout and in some other cases.
But implicit typecasting is evil. Consider:   
```c++
tlib::tstring str = "Hello";
str + "World"
```
Now we are not sure that str would be type casted to const char * and or will stay as tstring and concatenated using the + operator of the tstring class. 
Instead of this typecast, we can overload with << operator.  
Note: Explicit keyword from c++ 11 onwards can be used to get away with implicit typecast evil  
Details: https://stackoverflow.com/questions/4096210/why-does-stdstring-not-provide-a-conversion-to-const-char

### 5. Deciding member functions, friend functions and non-member (free) functions
1. Comparison operators as non-member functions because both the objects are to be treated equally.   
It can also be defined as a member function like:  
```c++
bool operator == (const tstring & rhs) const;  
```
This is acceptable (notice const at the end). But non-member function is more efficient and is the rule of the thumb.
Details: https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421729#4421729  
https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading/4421719#4421719  
2. Output steam operator << also as the non member function. We can declare it as friend or non-member. As in this case we have c_str(), which returns const char * (the same as the private variable), it is better to go with this.   
3. Assignment operator += is better suited as member function as they modify the lvalue.   
4. Assignment operator + is better suited as non-member function. Can call += and lhs and rhs are to be treated equally.  
Notice the declaration of operator +   
inline tstring operator+(tstring lhs, const tstring& rhs)  
a. It returns the copy of the result, not the reference as they is no way around the copy.   
b. It takes in the lhs argument by value. The reason is same why we had to do this for operator=.  
c. += is more efficient that =. Prefer to use it in most cases.   
d. Array subscript operator [] is preferred to be used as the class member

### 6. Gtest is used as the testing framework

### 7. What Next?  
While reading about the how to implement iterator and how std::string is implemented - I landed on exploring c++ 11 book. After going through the exploration 64 'Traits and policies', I decided to park this implementation and restart policy based approach.
The policy based approach will take the traits which implements comparison like methods and allocator would implement storage based rules. Here we can use vector, deque, or an array based storage. 
Here are the signatures the new type:  
  
```c++
template< 
    class CharT, 
    class Traits = std::char_traits<CharT>, 
    class Allocator = std::allocator<CharT>
> class basic_string
```

Create issues to report any bugs or give the suggestions to improve the code


credits: The code has been inspired from LinkedIn Learning course by Bill Wienman (http:://bw.org) 
