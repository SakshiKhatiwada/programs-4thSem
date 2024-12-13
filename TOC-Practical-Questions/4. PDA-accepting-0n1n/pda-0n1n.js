let stack = [];   //stack for our PDA

//----> taking input from user

let input = prompt("Enter the string: ");
 console.log(input);
  console.log(input.length);
 console.log(stack.length);
let top = -1;    //initializing top 
let state = 'q0';

for (let i=0; i< input.length; i++)
{
    //  console.log('inside for loop');
    //   console.log('input', input[0]);
   if (input[i] === '0' || input[i] === '1')  //to make sure input is only boolean
   {
    if (state === 'q0' && input[i] === '0' && top == -1 || input[i] === '0' && stack[top]==='0')
      {
          top++;
       stack.push('0');
        console.log('stack', stack);
       //  console.log(stack.length);
      }
   else if (state === 'q0' && input[i]=== '1' && stack[top] == '0')
      {
       stack.pop('0'); 
       top--;
       state = 'q1';
       //  console.log('haha', stack.length); --> this is called debugging using console dude 😩, took me 5 minutes to find the error 🤦‍♀️🤣
      }
   else if (state === 'q1' && input[i]=== '1' && stack[top] == '0')
     {  stack.pop('0');
       //  console.log('hehe',stack.length);
     }
   else{
       state = 'reject';
       //  console.log('reject state');
       break;
   }
   }
   else
   console.log("Wrong input");
}

 console.log(stack.length);
if (state !== 'reject' && stack.length === 0)
console.log('string is accepted!');
else
console.log('string is not accepted.');

