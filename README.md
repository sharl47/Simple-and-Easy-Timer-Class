# Simple and Easy Timer Class

This timer class is used to count a certain time duration. It works exactly likes a stop watch. It has four functions
start() to start the timer, stop() pause counting, reset() to reset the memory, and another template function read() to return its reading.

## Example
><strong>If John starts his timer at noon, after 2 minutes and 10 seconds, at 12:02:10 the timer
reads 2:10. If John stops his timer at 12:03:12, then it reads 3:12. Then he pushs start 
buttom again at 12:10:05, at 12:12:00 the timer reads 5:07. If he stops it at 12:13:00. 
The timer reads 6:07.</strong>

The example above is how we use a timer in real life. 

In the C++ world however, the default \<chrono> contains the stuff we need to count time.
But they are too complex for programmers. This example below is an example of using default C++
standard library to count the running time of std::sort() function.(Assuming we already have a vector
called [vec] to be sort)

    
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::duration time_elapsed;
    
    begin = std::chrono::steady_clock::now();
    std::sort(vec.begin(),vec.end());
    time_elapsed = std::chrono::steady_clock::now() - begin;
    
    std::cout << "Sorting a vector using std::sort cost "
              << std::chrono::steady_clock::duration_cast<std::chrono::milliseconds>(time_elapsed).count
              << " milliseconds." << std::endl;
              

This kind of syntax is too complex to use in real programming. This Simple and Easy Timer Class are designed
to make time counting easier in C++.

The example below is the equivalent code using Simple and Easy Timer Class.

    Timer timer; // declare a timer object
    timer.start(); // start your timer
    std::sort(vec.begin(),vec.end());
    timer.stop(); // stop the timer
    
    std::cout << "Sorting a vector using std::sort cost "
              << timer.read<Timer::milliseconds>(); // read the timer
              << " milliseconds." << std::endl;

There is a complete example in Main.cpp which count the time that std::sort() cost sorting 10000 ints.

## Public Members
* <strong> Default Constructor </strong>

* <strong> void start() </strong>
<br/>  It make timer begin running.

* <strong> void stop() </strong>
<br/>  It make timer stop running.

* <strong> void reset() </strong>
<br/>  It stops the timer and set its reading to zero.

* <strong> template \<typename Unit> int64_t read\<Unit>() </strong>
<br/>  This function template returns Timer's reading as an 64 bits int. The type argument of this 
function is the unit of time you want. The valid arguments are:
<br/>(be careful: read() returns an int)
  


    Timer::nanoseconds
    Timer::microseconds
    Timer::milliseconds
    Timer::seconds
    Timer::minutes
    Timer::hours

