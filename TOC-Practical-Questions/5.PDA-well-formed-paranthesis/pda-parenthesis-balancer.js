let stack = [];   //stack for our PDA

//----> taking input from user

let input = prompt("Enter the string: ");
//  console.log(input);
//   console.log(input.length);
//  console.log(stack.length);
let top = -1;    //initializing top 
let state = 'p';

for (let i=0; i< input.length; i++)
{
    if (input[i] === ']' || input[i] === '[')   //-> to make sure that the input string is correct
    {
        if ((state === 'p' && input[i] === '[' && top == -1) || (state === 'q' && input[i] === '[' && stack[top]==='[')) {
            top++;
            state = 'q';
            stack.push(input[i]);
        }

        else if(state === 'q' && input[i] === ']' && stack[top] === '[')
        {
            top--;
            stack.pop();
            if(stack.length === 0)
                state = 'p';
        }

        else {
            state = 'reject';
            break;
        }

    }
    else
    console.log('enter paranthesis only');
    throw new error('paranthesis only');

}

//  console.log(stack.length);
if (state !== 'reject' && stack.length === 0 && state === 'p')
console.log('string is accepted!');
else
console.log('string is not accepted.');



