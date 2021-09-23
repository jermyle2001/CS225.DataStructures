/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

#include <iostream>

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{
    // Your code here
/*
-Approach: we want to read the item, go down one in the stack
-We can store the item locally. Read its value via top(), store it 
-locally, pop it off the stack, call sum, push it back onto the stack,
-return added values.
*/

 //Base Case: Stack is empty
 if(s.empty())
 return T(); //Return default value for object

 //Not at base case, initiate approach
 T temp = s.top();
 s.pop();
 T temp2 = sum(s);
 s.push(temp);
 return(temp + temp2);







    return T(); // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{

    // @TODO: Make less optimistic
/*
- Note: input is of type queue, use queue's functions
-Check if the top of queue is '[' or ']'.
*/

stack <char> bracketstack;
//int count = 0; //+1 for '[', -1 for ']'.

while(input.empty() != true){
 if(input.queue::front() == '[' || input.queue::front() == ']'){ 
 /*
  -Base case: ][ is unbalanced. Look to see if ']' is first.
 */
  if(input.queue::front() == ']'){
   return false; //']' is at the front. It will always be unbalanced. 
  } 
  else{
   //count++; //Iterate count by +1 for '['
   bracketstack.push('[');
   input.pop(); //Pop item from queue
   break; //Break while loop
  }
 }
 //Iterate through queue by popping the topmost value
 input.pop();
}
//Finished with base case, iterate through queue to see if unbalanced
while(input.empty() != true){ //Loop through queue until empty
 /*if(count < 0){
 return false; //Count should never be less than 0. Return false.
 }*/
 if(input.queue::front() == '['){
 //count++;
 bracketstack.push('[');
 }
 if(input.queue::front() == ']'){
 //count--;
 if(bracketstack.empty() == true){
  return false; //Trying to push ']' bracket onto empty stack - means 
		//it will be unbalanced regardles
 }
 bracketstack.pop();
 }
 input.pop(); //Always pop item from queue regardless of what it is
}

//Queue has been exhausted, now check count

/*if(count == 0){ //If balanced, count should == 0
 return true;   //Balanced, return true
}
return false; //Unbalanced, return false
*/

if(bracketstack.empty() == false){//If stack is not empty, is unbalanced. 
			   //If it is empty, it's balanced.
 return false;
} 
return true;


}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;

    // Your code here
 queue<T> q2;
 int elementcount = 1;
 int evenodd = 1;
 unsigned size = q.size(); 
 while(q.empty() == false){
  //Check if odd or even
  //std::cout << "WhileLoop: evenodd = " << evenodd << " | elementcount = " << elementcount << std::endl;
  if(evenodd == 1){ //Odd function, don't reverse
  //std::cout << "No scramble. Pushing to q2." << std::endl;
   for(int j = 0; j < elementcount; j++){
    T element = q.queue::front(); //Get element
    q.pop(); //Remove element from queue
    q2.push(element); //Push element to new queue
    if(q.empty() == true){
     break;
    }//Check to see if queue empty. If so, exit for loops.
   }
  elementcount++; //Increment elementcount
  evenodd++; //Set next value to even
  } //End of odd iterator
  else{ //Else, it's an even so scramble
   //std::cout << "Scrambling..." << std::endl;
   for(int j = 0; j < elementcount; j++){ //First push all elements to 
					  //stack
    T element = q.queue::front(); //Get element
    q.pop(); //Remove element from queue
    s.push(element); //Push element to stack
    if(q.empty() == true){
     break;
    } //Check to see if queue empty. If so, exit for loops.

   }
     //Now pop items from stack into queue in order  
   for(int j = 0; j < elementcount; j++){
    T element = s.top(); //Get element
    s.pop(); //Pop element from stack
    q2.push(element); //Push element to temp stack
    if(s.empty() == true){
     //If stack is empty, we can terminate or break loop
     break;
    }
   }
   evenodd--;
   elementcount++;
  } //End of Else loop
 if(q.empty() == true){
     break;
    } //Check to see if queue empty regardless  
 } //End of outer FOR loop

//Now we have to push new queue into old queue

while(q2.empty() == false){
 T element = q2.queue::front(); //Get element
 q2.pop(); //Remove element from temp queue
 q.push(element); //Push element into old queue
}



} //End of function
}
