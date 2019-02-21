----------------------
+++Online Tutorials+++
----------------------
You Don't Know JS
    https://github.com/getify/You-Dont-Know-JS
Mozilla Web Docs
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Introduction
    https://developer.mozilla.org/en-US/docs/Web/JavaScript/A_re-introduction_to_JavaScript

```javascript //provides prompt function for node
function prompt(question, callback) {
  var stdin = process.stdin,
    stdout = process.stdout;

  stdin.resume();
  stdout.write(question);

  stdin.once('data', function (data) {
    callback(data.toString().trim());
  });
}
```

    ================
    YOU DONT KNOW JS
    ================

Built-in Types:
(primitives)
    string
    number
    boolean
    null
    undefined
    symbol (new to ES6)
(Object)

You can use `typeof` to check the type of a variable

Objects in Javascript are like hashmaps: values tied to their properties (aka 'keys'). You can access a property's value either with the . notation or ['bracket'] notation. Bracket notation either requires a `string` literal or an expression that evaluates to a `string`. That string is then check against the object's property list and the the value of that property is returned.

Arrays are special objects where values where the properties are numerical indices instead.

Functions are also objects.

================================================================================

Built-in Type Methods
---------------------
For a full reference list, check out
    https://www.tutorialspoint.com/javascript/javascript_builtin_functions.htm

Coercion
--------
Javascript has implicit type coercion, but you can also explicitly type coerce by wrapping the value with the type you want to coerce to.

Truthy & Falsy
--------------
A truthy value in Javascript is a value that is considered `true` when evaluated in a Boolean context. All values are truthy except for : "", 0, -0, NaN, null, undefined, false.
A value is `true` only if it is explicity equal to Boolean `true` when compared with the strict equality `===` sign (similarly for `false`).

Equality
--------
The equality `==` sign will type coerce.
The strict equality `===` will not.

Inequality
----------
Inequality signs `<, >, <=, >=` will all type coerce.
There is no 'strict inequality' sign in Javascript.

================================================================================

Function Scopes
---------------
Anything `var` declared will belong to the current function scope (which includes nested functions of the current function). It can be thought of as being 'hoisted' to the top of the function scope where it was declared in. `function` declarations are also hoisted, although `var` hoisting is discouraged while `function` hoisting is acceptable.

Conditionals
------------
Same as most programming languages.

Strict Mode
-----------
Introduced in ES5, enable strict mode in the current scope by including the string `"strict mode";` at the top of the scope.

Function As Values
------------------
Functions are first class citizens in Javascript. You can assign functions to variables which can then be used for function calls.

Immediately Invoked Function Expressions (IIFEs)
------------------------------------------------
When you declare a function, it is not executed unless it is explicitly called. You can run it upon declaration by surrounding the function declaration with (brackets followed by a empty pair of brackets)().
You can also assign IIFEs to variables:
```javascript
var x = (function IIFEx() {
    return 42;
})();
var y = (function IIFEy() {
    return 42;
});
x; //42
y(); //42
```

Closure
-------
Closures are a way to "remember" and continue to access a function's scoped variables even after the function has finished/ is not currently running.

```javaScript
function makeAdder(x) {
  function add(y) {
    return y + x;
  };
  return add;
}

addv1 = makeAdder(6) //this adder will remember to add 6
addv2 = makeAdder(10) //this adder will remmeber to add 10

addv1(3) //3 + 6 = 9
addv2(3) //3 + 10 = 13
```
The most common usage of closures is the module pattern. Modules has its implementation details hidden from the outside world, as well as a public API that is accessible from the outside world.
(insert book example here)

this
----
If a function has a `this` reference inside it, that reference usually points to an object. But which object it points to depends on how the function was called. It is important to realize that, unlike most OOP languages, `this` does not refer to the function itself. I actually quite disagree with the author on this fact, it seems like `this` will always point to the object from where the function was called from. Even in java `this` does not point to the constructor function itself but rather the object that the constructor function belongs to.

prototypes
----------
When you reference a property of an object that doesn't exist, JavaScript will will automatically use that object's internal prototype reference to find another object to look for that property on. You can think of it as a fallback of the property that is missing. The linking between an object and its prototype objects happens when the object is first created. For example you can type

```javascript
var bar = Object.create(foo)
```
and the object bar was created with the prototypal link to object foo. Kind of like inheritance. However the more natural way of applying prototypes is a pattern called 'behavior delegation', where you intentionally design your linked objects to be able to delegate from one to the other for parts of the needed behavior. That sentence sounds kind of convoluted but the way I understand it is that Inheritence models real world relationships where many objects extend the properties of a parent object (the parent relationship is emphasized), while Behavior Delegation is just the dependency of objects on other objects for the required behavior (the existence of a Parent is deemphasized).

Old v New in JavaScript
-----------------------
-Polyfilling-
-Transpiling-

Non-JavaScript
--------------
In reality, a good chunk of JS code you write will not, strictly speaking, directly controlled by JavaScript. For example:
```javascript
var el = document.getElementById("foo");
```
The `document` variable exists as a global variable when your code is running in a browser. It's not provided by the JS engine, nor is it particularly controlled by the JavaScript specification. It has the form of something that resembles as normal JavaScript object, but not really. It's a special object often called a 'host object'

================================================================================

    ===================================
    YOU DON'T KNOW JS: SCOPE & CLOSURES
    ===================================

    -------------------------
    CHAPTER 1: WHAT IS SCOPE?
    -------------------------

On Compilation
--------------
JavaScript compilation is somewhere between C and Python. Rather than compiling everything before running, or intepreting the code as we go, JavaScript compiles as we go, and runs it immediately afterward (usually within microseconds).

How a variable gets assigned
----------------------------
Characters:
Engine - Responsible for start-to-finish, as well as execution of the program
Compiler - Parses source code into an Abstract Syntax Tree(AST), then generates machine executable code from it
Scope - Collects and maintains a lookup list of all declared identifiers, and enforces a strict set of rules on how these are accessible to the currently executing code

```javascript
var a = 2;
```

1) The Compiler first sees `var a` and asks Scope if `a` already exists in the current scope. If yes, Compiler ignores that line. Otherwise, Compiler asks Scope to declare a new veriable called `a` for that current scope.
2) Compiler then lexes, parses & generates machine executable code for the Engine to later execute the `a = 2` assignment. During execution Engine will ask Scope if there is a variable called `a` accessible in the current scope collection. If so, Enginer uses that variable. Else, it will look into the next outer scope until it can find `a`. If Scope's search hits the global level and still cannot find `a`, the Engine raises an error.

The Engine performs two kinds of lookups with Scope, LHS(Left Hand Side) and RHS(Right Hand Side) lookups. Put simply, LHS lookups involve looking for a container variable to assign a value to (as these most commonly occur on the left side of the `=` sign) while RHS lookups involve looking for the value of a particular variable (which commonly occur on the right side of the `=` sign)

LHS lookup === value assignment (it is a 'lookup' because you need to lookup the container variable in the current scope in order to assign a value to it)
RHS lookup === value evaluation (it is a 'lookup' because you need to lookup the value assigned to some variable in the current scope. The more natural way of thinking of a 'lookup', compared to a 'LHS lookup')

HOWEVER that does not mean LHS & RHS lookups always occur on the left and right of an `=` sign respectively. Sometimes there can be implicit assignment, as is when you pass in values as function parameters and those values get implicitly assigned to the various function parameter variables.

See the code below and check how many times an LHS or RHS lookup occurs?
```javascript
1│function display(a) {
2│    console.log(a);
3│}
4│display(2);
```
The Engine presumably skips the first 3 lines. Yes, javascript functions ARE objects. But the engine doesn't actually lookup a container variable `display` and assign an anonymous `function(a) { console.log(a) }` to the `display` variable during runtime. This behavior is already defined in the machine code that the Compiler generated, so there's no need to instantiate function values at runtime.
    So the Engine never executes any machine code for function declarations when it encounters them, but instead uses them as instruction manuals when they stumble upon a function call? Does the compiler even generate any executable instructions for function declarations?
Instead the Engine will goto line 4 and require an RHS lookup to see what function `display` entails. This is where an implicit assignment (or, LHS lookup) occurs. The Engine implicitly assigns the value `2` to the variable `a` since `2` was passed in as the function parameter `a`.
Then in line 2 the Engine will make an RHS lookup for the console object, and to resolve the property value of `log`.
`log` itself is another function that will assign whatever value was passed in as its arguments (to print it as output). Another implicit assignment i.e. LHS lookup. To recap, 2 was implicitly assigned to `a` in `display()`, and which was again implicitly assigned to whatever variable in the native implementation of `.log()`. Both implicit assignments first involved an RHS lookup of the function value in order to carry out the function.
So, 2 RHS lookups and 2 LHS lookups.

display(2) -> look for display() function value (RHS lookup)
assign 2 to argument variable 'a' (LHS lookup)

Quiz (find number of LHS and RHS lookups by Engine!):
```javascript
function foo(a) {
    var b = a;
    return a + b;
}
var c = foo(2);
```
Quiz Answer attempt:
LHS lookup c (variable)
RHS lookup foo (function)
LHS lookup a (parameter of foo)
implicity assign 2 to a
LHS lookup b (variable)
RHS lookup a
implicitly assign value of a (which is 2) to b
RHS lookup a, b, add them together and return the value
explicitly assign 4 to c
Answers: Mostly correct, only the lookup to foo is RHS not LHS (changed my answer)

Nested Scope
------------
If a variable lookup (both LHS and RHS) cannot be found within the current scope, the Engine will consult the next outer scope until it finds it, or reaches the global (which is the outermost) scope and terminates its search.

LHS vs RHS scope errors
-----------------------
```javascript
1│function foo(a) {
2│  console.log( a + b );
3│  b = a;
4│}
5│foo(2);
```
When the Engine encounters `b` in line 2, the RHS lookup for it will fail because `b` has not been defined in the Scope yet. This will throw a `ReferenceError`. Basically whenever an RHS lookup fails even after reaching the global scope, it will throw a `ReferenceError`.

By contrast if an LHS lookup fails in NON STRICT MODE, the Global Scope will create a new variable of that name in the global scope, and hand it back to Engine. In Strict Mode, all variables have to be declared before that can be assigned values, the Scope will no longer create variables in the global scope and the Engine would then throw a `ReferenceError`.

If a value is found for an RHS lookup but you try to do something impossible with that value, such as trying to execute-as-function a non-function value, or reference a property of `null` or `undefined` value, the Engine throws a `TypeError` instead. So `ReferenceError` is Scope resolution-failure, `TypeError` means Scope resolution was successful but there was an illegal action attempted with the value.

    ------------------------
    Chapter 2: Lexical Scope
    ------------------------

```javascript
1│function foo(a) {
2│  var b = a * 2;
3│  function bar(c) {
4│    console.log( a, b, c );
5│  }
6│  bar(b * 3);
7│}
8│foo( 2 ); // 2 4 12
```
Scope 1: global scope, contains `foo`
Scope 2: `foo` scope, contains `a`, `b` and `bar`
Scope 3: `bar` scope, contains `c`

Scope lookups stop when it first finds a match - if there was a separate `c` variable in the `foo` scope, it would have been ignored by console.log() in line 4 as the `bar` scope already contains a `c` variable. Such ignored variables are known as shadowed variables -- outer scope variables that have already been defined in the current scope.

There are ways to access shadowed variables, but those will slow your program down by preventing the engine from making optimizations. Alternatively, global variables are automatically properties of the global object (`window` in browsers, etc) so it is possible to reference a shadowed global variable not directly by its lexical name, but as a property of the global object e.g. `window.a` (since the global object is always accessible everywhere)). However, non-global shadowed variables still cannot be accessed (because non-global objects are not accessible everywhere).

-Lexical Scope vs Dynamic Scope-
Lexical scope means scope is defined at compile/author-time based on the location of where the function is declared. Contrastingly, dynamic scope is defined at runtime based on how that function is called. Lexical scope is more popular as it is simpler to reason about and analyse.

    -----------------------------------
    Chapter 3: Function vs. Block Scope
    -----------------------------------

You can think of a function as being declared, and then code added inside it but you can also think of it as wrapping an arbitrary section of code within a function, which effectively 'hides' that code and creates a scope bubble around it. This hiding can faciliatate in the 'Principle of Least Privilege', where you should expose only what is minimally necessary and hide everything else. Example:

```javascript
1│function doSomething(a) {
2│    b = a + doSomethingElse( a + 2 );
3│    console.log( b * 3 );
4│}
5│function doSomethingElse(a) {
6│    return a - 1;
7│}
8│var b;
9│doSomething( 2 ); //15
```
The `b` variable and the doSomethingElse(..) function are likely 'private' implementation details on how doSomething(..) works. Giving the current scope access to `b` and doSomethingElse(..) is unnecessary and also dangerous if they are used in unexpected ways. It is better to declare `b` and doSomethingElse(..) in their relevant scope like so:
```javascript
1│function doSomething(a) {
2│    function doSomethingElse(a) {
3│        return a - 1;
4│    }
5│    var b;
6│    b = a + doSomethingElse( a + 2 );
7│    console.log( b * 3 );
8│}
doSomething( 2 ); //15
```

Another benefit of hiding variables and functions inside a scope is to avoid unexpected collision between two different identifiers with the same name but different intended uses.

Libraries will typically create a single variable declaration, often an object, with a sufficiently unique name in the global scope. This object is used as a 'namespace' for that library, where library functions are made as properties of that object rather than global lexically scoped variables.

Alternatively, you can use a dependency manager to handle 'modules'(?). This way, no libraries ever add any identifiers to the global scope, but instead require to have their identifier(s) explicitly exported into another specific scope using the dependency manager. There is no 'magic' functionality here that is exempt from lexical scoping rules. They simply follow the rules of scoping to ensure that no identifiers are injected into any shared scope. Complicated but I think it just means they do their scope deconflicting thing for the programmer, which done manually would be tedious.

While we can wrap any snippet of code in a function to hide its variables or function declarations from the outside scope that encloses it, it's not necessarily ideal. The first is that we have to first declare a name for that function (while anonymous functions are possible in javascript, function declarations do not allow anonymous functions. That is, you cannot declare a function without a name. Why would you? Without a name, whatever function you just declared will never be referenceable by any means and is effectively useless), and also that function name will again pollute the global namespace. We also have to explicitly call the function by name so that the wrapped code actually executes.

To solve those 2 problems, you can wrap the function declaration in a (..) brackets, changing the function DECLARATION into a function EXPRESSION. Function declarations always have the first word in the line as `function`, while function expressions do not. This literally means anytime the word `function` isn't the first word in the line it's automatically a function expression. The point here is because function expressions do not need to be declared with function names, essentially allowing the creation of anonymous functions in JS. Then you can prepend the function expression with another pair of empty brackets () so that the function becomes an Immediately-Invoked Function Expression (IIFE).
```JavaScript
(function foo() { // <-- the function name `foo` does not pollute the enclosing namespace
    var a = 3;
    console.log( a );
})(); // <-- the empty brackets will immediately execute this function expression

(function() { // <-- you don't even need to give a name to function expressions in the first place, while you cannot do the same for function declarations.
 var a = 3;
 console.log(a);
})();
```
Note that there is a reason for the difference between function declarations & function expressions. The purpose of function declarations are for the Scope to assign the function object to a variable in the current scope. Hence if you try to declare an anonymous function you would confuse the Scope, because you're not providing a variable to store that function object in. More importantly function declarations (and declarations in general) are for the sole purpose of STORING values! Function declarations literally cannot do anything else but store values, and hence are unfit for being Immediately Invoked as an IIFE. Hence you have to somehow force the word `function` to not be the first thing in the line, which is what wrapping the whole declaration in a pair of brackets () does, since the opening bracket is now the first thing in the line. Bit cheesy but true.

While anonymous functions are quick and easy to type, they have no useful name in stack traces making it hard for debugging. They also cannot create recursive algorithms, since a name is required as a reference handle. Lastly function names are often helpful in providing more comprehensible code. Instead, consider using inline function expressions, which are bascially anonymous functions with a name.
```javascript
setTimeout( function() { // <-- this is an anonymous function
    console.log("I waited 1 second!");
}, 1000 );
setTimeout( function timeoutHandler() { // <-- this is an inline function expression
    console.log("I waited 1 second!");
}, 1000 );
```
This reasoning against anonymous functions actually makes sense, I wonder how hard it is to debug a Lisp program full of anonymous functions.

Block Scoping
-------------
Generally, new scopes are defined by functions. But you can also define new scopes by blocks (what counts as a block?). However a common error that trips developers up is that `var` declared variables are not block-scoped, they are function-scoped. For example
```javascript
for (var i=0; i<10; i++) {
    console.log(i);
}
```
we declare `i` directly inside the for-loop block since we only want the `i` to exists within the for-loop block and not outside. However `i` actually belongs to the function that houses the for-loop, since it was declared with `var` which ignores block scoping. To force variables to be declared within the current block scope, use `let` instead.

Using `let` to attach a variable is somewhat implicit. It can confuse you if you have a fuckton of (nested) blocks together. Explicitly group `let` declarations and all relevant uses of all variable(s) together in a block with curly {..} parenthesis to be clear.

In the case of loops, `let` actually rebinds the variable to each iteration of the loop. This will become significant when we discuss Closures.

Another little known fact is that any variable declared within the `catch` clause of `try/catch` are block-scoped to the `catch` block. E.g.
```javascript
try {
    undefined(); //illegal operation to force an exception
} catch (err) {
    console.log(err) //err is scoped within the catch block
}
console.log(err) // ReferenceError: `err` not found
```
Some linters will complain if you have two or more catch clauses with the same error variable name. The simple way around it is to just give separate names to each error variable i.e. 'err1', 'err2' and so on.

Block Scoping in Garbage Collection
-----------------------------------
Blocks can also be used to clearly isolate unnecessary variables so that they can be garbage collected, in cases where they are otherwise preserved by Closure (more on closure later).

Block Scoping and Refactoring
-----------------------------
When refactoring a block into 2 separate blocks, make sure any block-scoped `let` variables are duplicated into both functions.

const vs let vs var
-------------------
As discussed above `var` declared variables are scoped to the outer enclosing scope, while, `let` declared variables are scoped to the current block scope. `const` is the same as `let` (scoped to the current block scope) except any attempt to change that value later down the block results in an error.

Block scope refers to the idea that variables and functions can belong to an arbitrary block (generally any {...} pair) of code, rather than only to the enclosing function. Block scoping (let) and function scoping (var) can coexist, `let` is not necessarily superior to `var` as some believe so (Why?).

    -------------------
    Chapter 4: Hoisting
    -------------------

Declarations are hoisted to the top of the current scope. Assignments are not hoisted. The statement `var a = 2` is parsed as 2 separate parts, `var a` and `a = 2`. the Compiler handles the variable declaration, while the Engine handles the `a = 2` assignment. Thus, `var a` is hoisted but `a = 2` is not.

In the same vein, function declarations are hoisted but function expressions are not.
```javascript
foo(); // <-- runs fine
bar(); // <-- doesn't run because bar is declared but not assigned a function value (defaults to 'undefined').
function foo { ... } // <-- 'foo' function declaration hoisted
var bar = function baz() { ... } // <-- bar declaration hoisted, 'baz' function expression not hoisted
```

Functions declarations are hoisted first, then variable declarations. This can affect you if you do something silly like declaring duplicate function names within the same scope.

    ------------------------
    Chapter 5: Scope Closure
    ------------------------

    "Closure is when a function is able to access its lexical scope (i.e. its list of variables) even when that function is executing outside its lexical scope."

```javascript
1│function foo() {
2│  var a = 2;
3│  function bar() {
4│    console.log(a);
5│  }
6│  bar();
7│}
8│foo();
```
bar() still has access to variable `a` in the outer enclosing scope because of lexical scope lookup rules. Even though the `a` belongs to the lexical scope of `foo()`, `bar()` is still able to access the value of `a` while `bar()` is executing and `foo()` is not. Is this closure? Well, technically.. but not exactly. From an academic standpoint the function `bar()` has a closure over the scope of `foo()` simply because `bar()` is nested inside of `foo()`. But closure defined this way is not directly observable, not do we see closure exercised in the snippet (we don't?).

```javascript
1│function foo() {
2│    var 1 = 2;
3│    function bar() {
4│        console.log( a );
5│    }
6│    return bar;
7│}
8│var baz = foo(); // The internal function bar() and its lexical scope, is preserved by variable baz still referencing it
9│baz(); // <-- Whoa, closure was just observed
```
The function `bar()` has lexical scope access to the inner scope of `foo()`. We return `bar` as a value in line 6, i.e. returning the function object that `bar` itself references. We assign this function object, together with its lexical scope, to the variable `baz` in line 8. Even after the function `foo()` has ceased running, as long as baz is still referencing this function object, the function (again with all its lexically scoped variables) will be preserved and not garbage collected. This reference is called closure. So we therefore say that `baz` has closure over `bar`, and since `bar` has lexical scope closure over the inner scope of `foo()` that is how `baz` has access to the variable `a` well after the execution of `foo` has terminated?

Any way that functions can be passed around as values, and invoked in other locations, are all examples of observing/excercising closure.

```javascript
01│function foo() {
02│    var a = 2;
03│    function baz() {
04│        console.log( a ); //2
05│    }
06│    bar( baz );
07│}
08│function bar(fn) {
09│    fn(); // <-- here's closure
10│}
```
The inner function `baz()` and its lexical scope is implicitly assigned to the variable `fn` in line 8. Thus `fn` still references the inner function `baz()` even though `foo()` is not currently running (bar() is). When you call `fn()` you are really calling the function object that `baz` used to point to.

```javascript
01│var fn; // global variable
02│function foo() {
03│    var a = 2;
04│    function baz() {
05│        console.log( a ); //2
06│    }
07│    fn = baz;
08│}
09│function bar(fn) {
10│    fn(); // <-- here's closure
11│}
12│foo();
13│bar(); // 2
```
Again the inner function `baz()` is assigned, this time to a global variable (that all functions have access to). This global variable maintains a closure over `baz()` for the lifetime of this program.

Whatever facility we use to transport and innder function outside its lexical scope, it will maintain a scope reference to where it was originally declared, and whenever we execute it, that closure will be excercised.

The above code snippers are somewhat academic and artificially constructed to illustrate using closure. Now let's look at more common examples.

```javascript
function wait(message) {
    setTimeout( function timer() {
        console.log( message );
    }, 1000 );
}
wait("Hello, closure!");
```
`setTimeout` is a function that calls a function X after Y milliseconds, where Y is defined by the 2nd argument passed into the function (and X the first argument). `setTimeout()` has scope closure over the scope of wait(..), and thus has keeps a reference to the variable `message`. Well after `wait(..)` has finished executed `setTimeout()` is still able to access `message` this way, and prints `message` after 1000 milliseconds.

TL;DR wait() invokes setTimeout(), then wait() finishes execution. But setTimeout() is still running (since it has to wait for 1000 milliseconds before it can do its job), and hence has closure over wait()'s local variable `message`.

A Clarification on Closures
---------------------------
Some say that IIFEs alone exhibit closure.
```javascript
var a = 2;
(function IIFE() {
    console.log( a );
})();
```
The code above 'works', but it's not strictly an observation of closure. While the IIFE function does have closure over the outer variable `a`, it's still being executed in the same scope as it was declared. `a` is found via normal lexical scope lookup, not really via closure.

While closure might technically be hapening at declaration time, it is not strictly observable, which is as they say, 'a tree falling in the forest with no one to hear it'. Closure is really only excercised when the closed-over function is not executing in its original scope (i.e. within the parent function) but by a reference outside the parent function that was keeping the child function alive, even after the parent has 'died' (or is not currently executing).

Loops + Closure
---------------
Take a look at the follow code:
```javascript
for (var i=1; i<=5; i++) {
    setTimeout( function timer() {
        console.log( i );
    }, i*1000 );
}
```
Expected Behavior: Print 1,2,3,4,5 each at 1000,2000,3000,4000,5000 & 6000ms respectively
Actual Behavior: Prints 6,6,6,6,6 each at 1000,2000,3000,4000,5000 & 6000ms respectively

The timeout function callbacks are running well after the completion of the loop. 6 is printed because the loop terminates when i=6, not 5. We're trying to imply that each iteration of the loop creates its own copy of `i`, at the time of the iteration. So when `i` is currently 1, the `setTimeout()` designated for 1000 milliseconds later 'remembers' that his `i` was 1, not whatever `i` currently is after loop termination. But the way scope works is that all 5 `setTimeout()` functions are closed over the /same global scope/, which has only one `i` in it. Everytime the loop updates `i`, the value of this globally scoped `i` gets updated for every single `setTimeout()` function.

So we need a closured scope after each iteration of the loop. Previously we learnt that IIFE creates scope by declaring its own function and immediately executing it. Thus, we can preserve the 5 different states of `i` by enclosing it within an IIFE that executes 5 times.

```javascript
for (var i=1; i<=5; i++) {
    (function() {
        var j = i;
        setTimeout( function timer() {
            console.log( j );
        }, i*1000 );
    })();
}
```

note that
```javascript
for (var i=1; i<=5; i++) {
    (function() {
        setTimeout( function timer() {
            // <-- var j = i missing
            console.log( i );
        }, i*1000 );
    })();
}
```
You need another variable `j` that 'freezes' the progress of `i`, so that `setTimeout()` is no longer referencing `i` (which belongs to the global scope and has only one copy of) but rather `j` (5 different values created at different times in each IIFE loop iteration). Alternatively, just use `let` instead of `var` to create 5 different, block-scoped copies of `i` (you don't even need all the IIFE hoodoo).

The Module Pattern done with Closures
-------------------------------------

```javascript
var MyModules = function Manager() {
  var modules = {};

  /*
   * 'name' is the name of the function you're defining
   * 'deps' is a key value list of the dependencies that this function relies on. The key is the name of the dependency function, the value is ???
   * 'impl' is ???
   */
  function define(name, deps, impl) {
    for (var i=0; i<deps.length; i++) {
      deps[i] = modules[deps[i]];
    }
    modules[name] = impl.apply( impl, deps );
  }

  function get(name) {
    return modules[name];
  }

  return {
    define: define,
    get: get
  };
}();

MyModules.define(
  "bar",
  [],
  function(){
    function hello(who) {
      return "Let me introduce: " + who;
    }

    return {
      hello: hello
    };
  }
);

MyModules.define(
  "foo",
  ["bar"],
  function(bar){
    var hungry = "hippo";

    function awesome() {
      console.log( bar.hello( hungry ).toUpperCase() );
    }

    return {
      awesome: awesome
    };
  }
);

// var bar = MyModules.get( "bar" );
// var foo = MyModules.get( "foo" );

console.log(
  MyModules.get("bar").hello( "hippo" )
); // Let me introduce: hippo

MyModules.get("foo").awesome(); // LET ME INTRODUCE: HIPPO
```
Holy fuck the above snippet is way too confusing for me. I think I will have to come back to this in the future.

================================================================================

    ===========================================
    YOU DON'T KNOW JS: this & OBJECT PROTOTYPES
    ===========================================

    ------------------------
    CHAPTER 1: this OR THAT?
    ------------------------

A weird attempt that circumvents function arguments; instead, use 'call' to replace all instance of `this` within the function with whatever is passed into the `call` function
```JavaScript
00|function identify() {
01|  return this.name.toUpperCase();
02|}
03|
04|function speak() {
05|  var greeting = "Hello, I'm " + identify.call( this );
06|  console.log( greeting );
07|}
08|
09|var me = {
10|  name: "Kyle"
11|};
12|
13|var you = {
14|  name: "Reader"
15|};
16|
17|identify.call( me ); // KYLE
18|identify.call( you ); // READER
19|
20|
21|speak.call( me ); // Hello, I'm KYLE
22|
23|speak.call( you ); // Hello, I'm READER
```

This code snippet allows the identify() and speak() functions to be re-used against multiple context (me and you) objects, rather than needing a separate version of the function for each object. Instead of relying on this, you could have explicitly passed in a context object to both identify() and speak().

```JavaScript
01|function identify(context) {
02|  return context.name.toUpperCase();
03|}
04|
05|function speak(context) {
06|  var greeting = "Hello, I'm " + identify( context );
07|  console.log( greeting );
08|}
09|
10|var me = {
11|  name: "Kyle"
12|};
13|
14|var you = {
15|  name: "Reader"
16|};
17|
18|identify( you ); // READER
19|speak( me ); // Hello, I'm KYLE
```

However, the this mechanism provides a more elegant way of implicitly "passing along" an object reference, leading to cleaner API design and easier re-use. (Is it? It doesn't feel like so)

The more complex your usage pattern is, the more clearly you'll see that passing context around as an explicit parameter is often messier than passing around a this context. (We'll see)

Confusions
----------
`this` isn't a handle for the function that contains it.

`this` isn't a handle for the object that contains it.

`this` isn't a handle for the lexical scope of the current function or block. It's not the same as how you can access to the global object's (e.g. the current window) lexical scope with window.<property>.

```javascript
function foo() {
  var a = 2;
  this.bar();
}

function bar() {
  console.log( this.a );
}

foo(); //undefined
```

You can see an attempt to reference bar()'s scope from within foo() with this.bar(), as though `this` was the encompassing scope containing the variables `foo` & `bar`. Whenever you try bridging lexical scopes with something similar like this, remember that _THERE IS NO BRIDGE_. It's simply not possible to refer to another lexical scope with `this`.

What's `this`?
--------------
`this` is not a compile-time binding but rather a runtime binding. It thus depends on how the function containing `this` was called.

The Call-site
-------------
The call-site is the location in code where a function was called (NOT where a function was declared). Usually this trivially means 'finding the location where the function was called from', but some coding patterns can obscure the true call-site.
What's important is to think about the 'call-stack', the stack of functions that have been called to get us to the current moment in execution. The call-site of a function is always the function that was invoked BEFORE the current executing one.

    ------------------------------------
    CHAPTER 2: this ALL MAKES SENSE NOW!
    ------------------------------------

The 4 rules of `this` binding
-----------------------------

    ---------------
    Default Binding
    ---------------

    Consider the following:
    ```javascript
    1|function foo() {
    2|  console.log( this.a );
    3|}
    4|
    5|var a = 2;
    6|
    7|foo(); //2
    ```
    If you didn't already know, variables declared in the global scope (like var a = 2 in line 5) are instantiated as the global object's properties. In this case when foo() is called, `this` points to the global object. Why? because foo() was called with a plain, un-decorated function reference(?). Meaning by default `this` will end up being the global object, I think.

    If strict mode is set, Default Binding no longer applies and `this` ends up as `undefined`. A subtle detail is that only the strictness of the scope where `this` was defined in matters. Since you can declare "use strict"; locally, if strict mode wasn't active in the foo() function declaration Default Binding still works.
    But generally mixing strictness is discouraged, unless you are forced to tangle with some third party libraries that require strict mode turned off.


    ----------------
    Implicit Binding
    ----------------

    Consider:
    ```javascript
    01|function foo() {
    02|  console.log( this.a );
    03|}
    04|
    05|var obj = {
    06|  a: 2,
    07|  foo: foo
    08|};
    09|
    10|obj.foo(); // 2
    ```

    Notice that the global function foo() was declared first, then made a reference property of the object `obj`. Whether foo() was declared as a property of `obj` or declared first and made a reference property later (as this snippet shows), in neither case is the function really "owned" or "contained by" the `obj` object (What makes you say so? If you declare `foo()` as an `obj` property it seems pretty straightforward that the function is a property of `obj`.)

    But the call-site uses the `obj` context to reference the function, so you could say that the `obj` object "owns" or "contains" the function reference at the time the function is called in line 10 (????? are you contradicting your earlier assertion that foo() is not really "owned" or "contained by" `obj`??????).

    When there is a context object for a function reference, the Implicit Binding rule says that its /that/ object which should be used for the function call's `this` binding. So in line 2 `this.a` is really `obj.a` when `foo()` is called in the context of `obj` on line 10.

    Also, only the last object directly next to the foo() call matters. If you call obj1.obj2.foo(), `this` really refers to `obj2`.

    Loss of Implicit Binding/ Fallback to Default Binding
    -----------------------------------------------------

    Consider:

    ```javascript
    01|function foo() {
    02|  console.log( this.a );
    03|}
    04|
    05|var obj = {
    06|  a: 2,
    07|  foo: foo
    08|};
    09|
    10|var bar = obj.foo; // function reference/alias!
    11|
    12|var a = "oops, global"; // `a` also property on global object
    13|
    14|bar(); // "oops, global"
    ```
    Even though bar appears to be pointing to the foo() property of obj, what is the foo() property of obj() pointing to? It is pointing to the global function foo().
    So when we call bar(), what we are really doing is calling the global foo() function. And since bar() was not invoked as a property of any object, `this` falls back to the Default Binding of the global object.

    Consider a more common example where you invoke obj.foo through a callback by some other library's function.
    ```javascript
    01|function foo() {
    02|  console.log( this.a );
    03|}
    04|
    05|var obj = {
    06|  a: 2,
    07|  foo: foo
    08|};
    09|
    10|var a = "oops, global"; // `a` also property on global object
    11|
    12|setTimeout( obj.foo, 100 ); // "oops, global"
    ```

    You can tell that the in-built function setTimeout does not respect how foo() was passed in as obj.foo. You might as well have passed in the global function foo. How to force a callback to respect how you wish `this` to take its context? Using explicit binding, of course.

    ----------------
    Explicit Binding
    ----------------

    With Implicit Binding, you saw that we had to mutate the object in question to include a property reference to the external function foo, and use this property reference to implicitly bind `this` to the object. It's not exactly a clean pattern to implement. Luckily, You can avoid tacking on extra object properties altogether.

    All functions in JS have some special utilities available to them (via their [[Prototype]] -- more on that later). Two of these utilities are the call(..) & apply(..) methods. Technically, some JavaScript environments may include their own "special" (a kind way of putting it) functions that do not include this basic functionality but let's just pretend they don't exist for now.

    How call(..) & apply(..) work is that the first argument passed in is the object reference that you want `this` to point to, followed by the other arguments that function normally takes. So rather than making foo() a property of `obj` and calling obj.foo, instead call foo.call(obj) and all references of `this` in foo() will explicitly use `obj` as their reference.

    Unfortunately Kyle Simpson (the author of this book) says it's still not enough to prevent a function from losing its intended `this` binding, or preventing it from being paved over by a framework etc. Which is really weird because I expect something introduced as an "Explicit Binding" rather than an "Implicit" one to specifically prevent such behaviour. What gives? Anyway an even more explicit binding, called "Hard Binding", exists that solves just the issue (which begs the questions of whats the difference is between an Implicit Binding and an Explicit Binding).

    Hard Binding
    ------------

    ```javascript
    01|function foo() {
    02|  console.log( this.a );
    03|}
    04|
    05|var obj = {
    06|  a: 2
    07|};
    08|
    09|var bar = function() {
    10|  foo.call( obj );
    11|};
    12|
    13|bar(); // 2
    14|setTimeout( bar, 100 ); // 2
    15|
    16|// `bar` hard binds `foo`'s `this` to `obj`
    17|// so that it cannot be overriden
    18|bar.call( window ); // 2
    ```

    Notice that line 10 is basically explicit binding in action. But now you wrap that explicitly-bound function call in a new variable (called 'bar' in this case) so that no matter who are where bar is called, it will always explicitly call foo with `obj` as the `this` reference. This is both a hard and strong binding.

    Note: As of ES6, the hard-bound function produced by bind(..) has a `.name` property that derives from the orginal target function. In other words,
    bar = foo.bind(..)
    should have a bar.name value of "bound foo", which should show up in a stack trace.

    API call "Contexts"

    Many libraries' functions as well as built in JavaScript ones provide an optional parameter, usually called "context", which is used to ensure your callback function uses a particular `this`. For instance:

    ```javascript
    01|function foo(el) {
    02|  console.log( el, this.id );
    03|}
    04|
    05|var obj = {
    06|  id: "awesome"
    07|};
    08|
    09|// use `obj` as `this` for `foo(..)` calls
    10|[1, 2, 3].forEach( foo, obj ); // 1 awesome  2 awesome  3 awesome
    ```

    Notice that on top of taking a function "foo", .forEach() accepted an extra argument "obj" which it would make as the context of `this` in foo().

    -------------
    `new` Binding
    -------------

    The fourth and final rule for `this` binding requires us to clarify something about functions and objects in JavaScript.

    In traditional class-oriented languages, "constructors" are special methods belonging to classes. When a class is instantiated as an object, the constructor of a class is called, which looks something like:

    ```javascript
    something = new MyClass(..);
    ```

    JavaScript too has a `new` operator. In JavaScript, constructors are just functions that happen to be called with a `new` operator in front of them. They are not attached to classes, they aren't even special functions. They're just regular functions that got hijacked by the use of `new` in their invocation. That means any regular function in JavaScript can be prepended by a `new` to become a constructor call. It's not really a constructor /function/, more like a /construction call/ of a function.

    When a function is invoked with a `new` in front of it, four things happen:
    1) A brand new object is created
    2) The newly constructed object is [[Prototype]]-linked
    3) The newly considered object is set as the `this` binding for that function call
    4) Unless the function returns its own alternate object, the `new`-invoked function call will return the newly constructed object (its default behaviour).

    Notice step 3, this is the final way `this` can be bound to an object (on top of the aforementioned Default Binding, Implicit Binding & Explicit Binding).

Binding Priority
----------------

Explicit Binding always takes precedence over Implicit:

```javascript
obj1.foo.call( obj2 ); // obj2 is explicitly bound to foo. obj1 is implicitly bound to foo. Explicit wins, so `this` in foo points to obj2
```

While new-Binding takes precedence over Explicit Binding (even if it's an Explicit Hard Binding). There's quite a detailed exploration of this in the book but my god is it complex. Just know that new > Explicit > Implict > Default.

Passing `null` as reference to bind(..), apply(..) or call(..)
--------------------------------------------------------------

Sometimes you'd like to call some function, but the arguments you want to pass in are all contained in an array. You could find some way to manally extract each argument from the array and pass it into the function, -OR- you could use the apply(..) function that takes in an array of arguments and spreads them out for you.

Problem is, apply(..) requires an argument as the reference for `this`, but you don't want to pass it any reference for `this`. You just want to use apply(..) on the function. In this case you can just pass in a `null` as the `this` reference and it will work.

You can also use bind(..) for partial function application (a subset of currying). Let's say a function takes in 2 arguments, but you want to pass in only one argument and return an function that accepts the remaining argument. You can do this with bind(..) but bind(..) again requires a `this` reference as the first argument. Just pass in a `null` instead.

Example:

```javascript
01|function foo(a,b) {
02|  console.log( "a:" + a + ", b:" + b );
03|}
04|
05|// spreading out array as parameters
06|foo.apply( null, [2, 3] ); // a:2, b:3
07|
08|// currying with `bind(..)`
09|var bar = foo.bind( null, 2 );
10|bar( 3 ); // a:2, b:3
```

In ES6 you can now 'spread out' arguments in an array without needing apply(..) using the `...`spread operator like this: foo(...[1,2,3,4]). However there is still no syntactical way to partially apply functions without bind(..) so the aforementioned method is still relevant.

An even safer way than passing `null` into bind(..), apply(..) or call(..)
--------------------------------------------------------------------------
Rather than passing in `null`, you can pass in an empty object created with `null`. The book doesn't explain why passing `null` might be dangerous in the first place, but maybe that's just the nature of `null`. Example:

```javascript
01|function foo(a,b) {
02|  console.log( "a:" + a + ", b:" + b );
03|}
04|
05|// our empty object
06|var ø = Object.create( null );
07|
08|// spreading out array as parameters
09|foo.apply( ø, [2, 3] ); // a:2, b:3
10|
11|// currying with `bind(..)`
12|var bar = foo.bind( ø, 2 );
13|bar( 3 ); // a:2, b:3
```

Indirection
-----------

```javascript
01|function foo() {
02|  console.log( this.a );
03|}
04|
05|var a = 2;
06|var o = { a: 3, foo: foo };
07|var p = { a: 4 };
08|
09|o.foo(); // 3
10|(p.foo = o.foo)(); // 2
```
On line 9 foo() is implicitly bound to object o so the value of this.a is implicitly bound to object o's value of a, which evaluates to 3 as expected.
However on line 10 the expression (p.foo = o.foo) simply evaluates to a reference of the underlying foo() object so the call-site is just foo() and not p.foo() or o.foo(). Hence Default Binding applies and the value of a is the value of the global variable a (which is 2).

Softening Binding
-----------------
While Hard Binding is great and all, it prevents any overriding with Implicit or Explicit bindings. Here is a method defined by the author, called softBind(), which allows you to bind an object to a function but the result is still overrideable by the Implicit or Explicit binding methods.
The way it works is that it checks the value of `this` at call time and if it's `global` or `undefined`, it will bind the function to the object passed to it as the argument. Else it will leave `this` untouched.

```javascript
01|if (!Function.prototype.softBind) {
02|  Function.prototype.softBind = function(obj) {
03|    var fn = this,
04|      curried = [].slice.call( arguments, 1 ),
05|      bound = function bound() {
06|        return fn.apply(
07|          (!this ||
08|            (typeof window !== "undefined" &&
09|              this === window) ||
10|            (typeof global !== "undefined" &&
11|              this === global)
12|          ) ? obj : this,
13|          curried.concat.apply( curried, arguments )
14|        );
15|      };
16|    bound.prototype = Object.create( fn.prototype );
17|    return bound;
18|  };
19|}
```

Here are some examples demonstrating its use and effects:

```javascript
01|function foo() {
02|   console.log("name: " + this.name);
03|}
04|
05|var obj = { name: "obj" },
06|    obj2 = { name: "obj2" },
07|    obj3 = { name: "obj3" };
08|
09|var fooOBJ = foo.softBind( obj );
10|
11|fooOBJ(); // name: obj
12|
13|obj2.foo = foo.softBind(obj);
14|obj2.foo(); // name: obj2   <---- look!!! Implicit Binding still works
15|
16|fooOBJ.call( obj3 ); // name: obj3   <---- look! Explicit Binding still works
17|
18|setTimeout( obj2.foo, 10 ); // name: obj   <---- falls back to soft-binding
```

Lexical `this` a.k.a. arrow-functions
-------------------------------------

Normal functions follow the 4 rules of `this` binding covered above. But ES6 introduces a new kind of function that does not follow those rules: arrow-functions.

Arrow-functions are signified by the `=>` arrow symbol. Instead of using the old `this` binding rules, arrow-functions adopt the `this` binding from the lexical scope. Basically how people mistakenly used to think `this` behaved, now actually implemented in the language(?).

```javascript
01|function foo() {
02|  // return an arrow function
03|  return (a) => {
04|    // `this` here is lexically adopted from `foo()`
05|    console.log( this.a );
06|  };
07|}
08|
09|var obj1 = {
10|  a: 2
11|};
12|
13|var obj2 = {
14|  a: 3
15|};
16|
17|var bar = foo.call( obj1 );
18|bar.call( obj2 ); // 2, not 3!
```

Looks like rather than `this` pointing erratically everywhere depending on how it was called, arrow-functions cement where `this` points to during the object's creation and it doesn't change from then on.

The author advocates either using only lexical scope and avoiding `this` altogether, or embracing JavaScript's `this` mechanisms by understanding it fully and using it appropriately.

    ------------------
    CHAPTER 3: OBJECTS
    ------------------

Objects come in two forms: the declarative (literal) form, and the constructed form.

```javascript
01|var myObj = { // <-- Literal form
02|  key: value
03|  // ...
04|};
05|
06|var myObj = new Object(); // <-- Constructed form
07|myObj.key = value; // <-- Constructed form
```

Note: It's uncommon to use the "constructed form" for creating the objects as shown. You pretty much always want to use the literal syntax form.

Objects are one one the 6 primary types in JavaScript: String, Number, Boolean, Null, undefined & Object. We emphasize that /simple primitives/ like Strings, Numbers, Boolean, Null & Undefined are themselves NOT objects. It is a common mis-statement that "everything in JavaScript is an object". Null is sometimes referred to as an object, but that misunderstanding stems from a bug where `typeof null` returns `object` (which is not true).

Functions is a sub-type of object, basically a "callable object". Functions in JavaScript are said to be "first class" in that they are just normal objects (but with callable semantics bolted on) so they can be handled like any plain object.

Arrays are also a type of object, with extra bahavior. The organization of contents in arrays is slightly more structured than for general objects.

Built-in Objects
----------------
There are several other object sub-types built into the language, other than Functions and Arrays. For some of them, they seem to be directly related to their primitive counterparts (like String or Number) but they are actually more complicated than that

• String
• Number
• Boolean
• Object
• Function
• Array
• Date
• RegExp
• Error

These built ins may resememble actual types, even classes. But in reality, they really are just built in functions. Each of these built in functions can be used as a constructor, with the result being a newly constructed object of the sub-type in question.

To elaborate, the primitive value "I am a string" is a literal and immutable value. To perform objects on it such as checking its length or accessing its individual character contents, a String Object is required. Luckily, JavaScript type-coerces a string primitive into a string object when necessary, such that you almost never need to explicitly create the Object form. It is strongly advised that you stick with string primitives whenever possible rather than the rather than manually creating string objects.

`null` & `undefined` have no object wrapper form, only their primitive values. By contrast, `Date` values can only be created with with their constructed object form, they have no literal form counterpart.

Objects, Arrays, Functions & RegExps are all objects regardless of whether the literal or constructed form is used. The literal form is almost universally preferred, only use the constructed form if you need extra options.

`Error` objects are rarely created explicitly in code, but are created automatically when exceptions are thrown. They can be manually created with `new Error(..)` but it's often unnecessary.

Contents
--------
As mentioned earlier, objects are just groups of key-value pairs. In JavaScript an object key is known as a "property". Under the hood, only the properties are stored within the object, while where the values are stored at depend on the implementation details of the engine (could be in the object, could be not). The properties thus act as references for where the values are stored.

You can access a value using either the . operator or the [ ] operator. The .a syntax is usually referred to as "property" access, while the ["a"] syntax is usually referred to as "key" access. In reality they are one and the same, and it's just an informal naming. "property" access is the more commonly used term.

The main difference between the . operator & the [..] operator is that the . operator only accepts Identifier-compliant names after it. That means anything you cannot use as a variable name, you cannot use as a valid . operator property. While the [..] accepts basically any UTF-8/unicode compatible string, so yes, you can use emojis with it. Furthermore [..] accepts anything that evaluates into a string, so you can put functions in it provided the return value is a string. The [..] operator also accepts variables (while the . operator does not), which opens it up to all sorts of programmatic string manipulations. Beware! If you pass in anything other than a string (like a number for instance) JavaScript will first type coerce it into a string. This can lead to unexpected results.

ES6 adds /computed property names/, where you can specify an expression inside [sqaure brackets] which evaluate into a string as an object property. E.g.

```javascript
01|var prefix = "foo";
02|
03|var myObject = {
04|  [prefix + "bar"]: "hello",
05|  [prefix + "baz"]: "world"
06|};
07|
08|myObject["foobar"]; // hello
09|myObject["foobaz"]; // world
```

Property vs Method
------------------
Some developers make a distinction between accessing an object's property value (which they call "property access") and accessing an object's property function (which they call "method access"). Technically, functions never "belong" to objects so saying that a function that was accessed by an object's property reference is automatically a "method" seems a bit of a stretch of semantics.

What the author is arguing in the above paragraph is that object property functions aren't object methods the same way Java object methods are. Functions don't specially belong to an object in any way more than how any other value belongs to an object. This is especially telling since the `this` in a function is primarily affected by where it was called, not which object it belongs to. Bascially that "function" & method" terms are interchangeable in JavaScript.

ES6 adds a `super` reference, which is typically used with `class`. `super`, unlike `this`, follows static binding rather than late binding.

Arrays
------
Arrays are objects except it uses positive integers as its properties. You also declare arrays with [square brackets], while objects use {curly brackets}. Since arrays _are_ objects you can manually add your own array elements with the operator [..] as long as whatever is within the [..] evaluates to an integer. Take note that string integers will also end up being type coerced to integers (but only if it's a non-negative string).

```javascript
var myArray = [ 'zero', 'one', 'two' ];

myArray[1+1+1] = 'three';
myArray; // [ 'zero', 'one', 'two', 'three' ]

myArray["4"] = 'four';
myArray; // [ 'zero', 'one', 'two', 'three', 'four' ]

myArray["0"] = 'wah! banana';
myArray; // [ 'wah! banana', 'one', 'two', 'three', 'four' ]
```

Interestingly you are also allowed to add your own non-numeric properties to an array,although non-numeric properties will not affect the .length value of an array. Another thing to note is that all non-numeric properties of an array will be pushed to the end, i.e. they will not break up the numeric property chain.

```javascript
01|var myArray = [ "foo", 42, "bar" ];
02|
03|myArray.baz = "baz";
04|
05|myArray; // [ 'foo', 42, 'bar', baz: 'baz' ]
06|
07|myArray.length;  // 3
```

Duplicating Objects
-------------------
There isn't a built-in function in JavaScript to duplicate an object. The reason is because a deep-copy (which is what we think of when we want to duplicate something) requires you to duplicate everything inside the original object, all the way down. But JavaScript allows you to push an array into itself; it's just adding a reference (to itself) after all. What if you tried to do a deep copy of something a something with a circular reference like that? Also, what does a duplicated function look like? Various JavaScript frameworks have their own implementations of this, but there is no universally agreed answer.

If an object is JSON-safe, it can be deep copied by first being serialized into a JSON string then re-parsed back into a JSON object.

```javascript
var deepCopyObj = JSON.parse( JSON.stringify( originalObj ) );
```

Shallow copying is fairly straightforward however, so ES6 has now defined an `Object.assign(..)` that accepts a target object as the first parameter, and one or more source objects to copy from. It iterates all over all the enumerable, owned keys (immediately present (meaning what?)) on the source object(s) and copies them (by simple `=` assignment only) to the target.
You may ask, if it's a shallow copy, what difference does this have over directly assigning the new object to the old object like so:

```javascript
var shallowCopyObject = originalObject;
```

Mainly this assignment method doesn't really create a copy, it's simply a reference to literally the same originalObject. While the shallow copy method means a new object is created, except all the properties are referencing the same values as the original object.

Example of Shallow Copying:

```javascript
01|function anotherFunction() { /*..*/ }
02|
03|var anotherObject = {
04|  c: true
05|};
06|
07|var anotherArray = [];
08|
09|var myObject = {
10|  a: 2,
11|  b: anotherObject,  // reference, not a copy!
12|  c: anotherArray,  // another reference!
13|  d: anotherFunction
14|};
15|
16|anotherArray.push( anotherObject, myObject );
17|
18|var newObj = Object.assign( {}, myObject ); // <-- Shallow Copying at work
20|
22|newObj.a;                     // 2
24|newObj.b === anotherObject;   // true
26|newObj.c === anotherArray;    // true
28|newObj.d === anotherFunction; // true
```

Property Descriptors
--------------------
Before ES5, there was no way for your code to inspect the various characteristics of properties, such as whether a property is read-only or not. But as of ES5, all properties are described with a *property descriptor*. Consider:

```javascript
01|var myObject = {
02|  a: 2
03|};
04|
05|Object.getOwnPropertyDescriptor( myObject, "a" );
06|// {
07|//    value: 2,
08|//    writable: true,
09|//    enumerable: true,
10|//    configurable: true
11|// }
```

As you can see, the property descriptor (called a "data descriptor" since it's only for holding a data value) for our normal object property a contains the value of the property, as well as whether it is writable, enumerable or configurable.

In fact, you can manually add/edit an object property by adding/editing a property descriptor with the `Object.defineProperty(..)` function:

```javascript
01|var myObject = {};
02|
03|Object.defineProperty( myObject, "a", {
04|  value: 2,
05|  writable: true,
06|  configurable: true,
07|  enumerable: true
08|} );
09|
10|myObject.a; // 2
```

However you generally don't want to manually do this unless you want to modify one of the descriptor characteristics from its normal behavior.

    --------
    Writable
    --------

    Whether you can edit the value of a property is determined by the property descriptor's `writable` attribute.

    If you define/edit a property descriptor's `writable` value to be false, subsequent attempts to change the value of that property will fail. It will either fail silently in non-strict mode, or throw a `TypeError` in strict mode if you try to change a property you cannot change(why a `TypeError`, I don't know).

    ------------
    Configurable
    ------------

    Whether you can edit the property descriptor of a property is determined by the property descriptor's `configurable` attribute.

    As you might suspect, setting `configurable` to false comes with a great downside of being a one-way action. Once you set a property descriptor to be non-configurable, ironically you can no longer configure the property descriptor to change it back to become configurable again. You can however still edit the value of the property (if the `writable` field of the property descriptor is true), you just cannot edit the property descriptor of that property anymore.
    Furthermore, while you can still edit the property's value you will be unable to delete the property from that object with the `delete` function. It will fail silently (unless you're on strict mode? TBC).

    If you try to do anything to the property descriptor after doing the one-way action of setting its `configurable` property to false, you will be met with a `TypeError`.

    ----------
    Enumerable
    ----------

    Whether the property shows up in a `for .. in` loop is determined by the property descriptor's `enumerable` attribute.

Immutability
------------

It is sometimes desirable to make properties or objects that cannot be changed (either by accident or intentionally). Here are several ways to achieve immutability in various nuanced ways.

However take note that they are all /shallow immutability/, that is, they only affect the object and its direct property characteristics. If an object A has a reference to another object B (could be an array, object, function etc), the contents of object B are not affected, and remain mutable. Wanting to create deeply entrenched immutability in objects is uncommon in JavaScript, if you find yourself wanting to do so perhaps it is better to take a step back reconsider your program design to be more robust against potential changes in object values.

    ---------------
    Object Constant
    ---------------

    Set the property descriptor to `writable: false` and `configurable: false` to make an object property constant. You have to do this for every property if you want the entire object to be a constant.

    -----------------
    Prevent Extension
    -----------------

    To prevent further properties from being added, use `Object.preventExtensions(..)`.

    ```javascript
    01|var myObject = {
    02|  a: 2
    03|};
    04|
    05|Object.preventExtensions( myObject );
    06|
    07|myObject.b = 3;
    08|myObject.b; // undefined
    ```

    In non-strict mode, the creation of b fails silently. In strict mode, it throws a TypeError.

    ----
    Seal
    ----

    `Object.seal(..)` essentially calls `Object.preventExtensions(..)` and also sets the property descriptor property `configurable: false` for all existing properties.

    ------
    Freeze
    ------

    `Object.freeze(..)` essentially calls `Object.seal(..)` and also sets the property descriptor property `wrritable: false` for all existing properties, meaning all existing values can no longer be changed. This is the highest level of immutability for an object.

    If you wish, you can also 'deep freeze' an object by recursively calling `Object.freeze(..)` on all objects within the object, all the way down. This can have drastic consequences by permanently freezing objects you didn't intend to freeze.

[[Get]]
-------

When you access an object property like like `myObject.a` you are actually performing a [[Get]] operation on myObject. [[Get]] searches myObject for a property named `a`, and if it finds it it returns the value accordingly. if it cannot find the property, it returns `undefined`. Contrast this behavior with when the JavaScript searches and fails to find some referenced variable, it throws a `ReferenceError` instead. But with object properties, all it does is return `undefined`. There is a way to tell whether the actual value of a property is `undefined` or whether the property just could not be found, we will cover that later.

[[Put]]
-------

When you assign a value to an object property like `myObject.a = 2` you are performing a [[Put]] operation on myObject.

1) If the property is an accessor descriptor, call the setter. (covered later) (wtf? then how am I supposed to understand this line?)
2) If the property descriptor has a `writable` value of `false`, either silently fail in non-strict mode or throw a `TypeError` in strict mode.
3) If the property doesn't exist yet, the operation is even more nuanced and complex, and will be covered in the [[Prototype]] section in Chapter 5
4) Otherwise, set the value of the existing property as usual.

Getters & Setters
-----------------

By default, adding or retrieving object properties are done with the [[Get]] & [[Put]] operations. ES5 introduces a way to override these default operations on a per-property level through the use of getters and setters. There may be ways to override the [[Get]] & [[Put]] operations for an entire object, but that will be covered in the later sections of the book.

Observe the following code:

```javascript
01|var myObject = {
02|  // define a getter for `a`
03|  get a() {
04|    return 2;
05|  }
06|};
07|
08|Object.defineProperty(
09|  myObject,  // target object
10|  "b",    // property name
11|  {      // descriptor
12|    // define a getter for `b`
13|    get: function(){ return this.a * 2 },
14|
15|    // make sure `b` shows up as an object property
16|    enumerable: true
17|  }
18|);
19|
20|myObject.a; // 2
21|
22|myObject.b; // 4
```

As you can see there is an alternative way to declare object properties, through the `get` keyword. `get` defines a getter function for some property such that accessing that property will return whatever the getter function returns.

As you can also see there exists a another field for the property descriptor called `get` which also takes in a getter function. Whenever you access this property, it returns whatever result the getter function returns. This can be seen as an equivalent way of doing the same thing in the paragraph above, except it uses the property descriptor rather than declaring it literally.

Since `a` & `b` are not properties in the usual sense, any attempt to assign a value to these properties in the usual away with the `=` sign will be silently ignored (or noisily in strict mode?). Hence you need to add setters for this. Setters should always follow getters, unless you want (weird) specific things like read-only properties you cannot change or write-only, unreadable properties that is are essentially useless.

Here's how a setter looks:

```javascript
01|var myObject = {
02|  // define a getter for `a`
03|  get a() {
04|    return this._a_;
05|  },
06|
07|  // define a setter for `a`
08|  set a(val) {
09|    this._a_ = val * 2;
10|  }
11|};
12|
13|myObject.a = 2;
14|
15|myObject.a; // 4
```

Note: In this example, we actually store the specified value 2 of the assignment ([[Put]] operation) into another variable _a_. The _a_ name is purely by convention for this example and implies nothing special about its behavior -- it's a normal property like any other.

Existence
---------

We mentioned earlier that both accessing a non-existent property and accessing a property with value `undefined` will return `undefined`. The way to tell whether a property exists in an object is to either use the ("a" in myObject) expression or the `myObject.hasOwnProperty("a")` function. The difference between the two is that (.. in ..) will travel through the [[Prototype]] chain (covered later) looking for the property while .hasOwnProperty(..) will not.

The function `.hasOwnProperty(..)` exists for all normal objects via delegation to `Object.prototype` (covered later). But it's possible to create objects that do not link to the Object.prototype (via Object.create(null)), and hence the function `.hasOwnProperty(..)` will not necessarily exist. The most robust way to check for property existence is to therefore use the `.call(..)` function a la

```javascript
Object.prototype.hasOwnProperty.call(myObject, "a");
```

Finally, an demonstrated advantage to JavaScript's insane `this` binding rules! (it uses explicit `this` binding here)

Enumeration
-----------
When a property is non-enumerable it is STILL ACCESSIBLE, it just doesn't turn up in a for..in loop of the object. It also still turns up in a property existence check.

Note: for..in loops will also loop over non-numeric properties, as long as those properties have `enumerable` set to `true` in their property descriptors. This can lead to undexpected behavior, use with caution.

myObject.propertyIsEnumerable("a") not just tests whether the myObject.a is enumerable, it also does an existence check equivalent to myObject.hasOwnProperty("a") (that is, it WILL NOT travel through the [[Prototype]] chain looking for "a").

Object.keys(myObject) will return an array of only the enumerable properties, while Object.getOwnPropertyNames(myObject) will return an array of ALL properties, enumerable or not. Both functions will NOT travel through the [[Prototype]] chain.

There's currently no function that will list all of an object's properties as well as its prototypes' properties, but you can do something equivalent by recursively travelling through the [[Prototype]] chain yourself and adding in to an array the properties returned by Object.keys(..) or Object.getOwnPropertyNames(..) for each level you travel through.

Iteration
---------

A for..in loop will loop through the properties, not values, of an object. What if you wanted to loop over the values instead?

With arrays, you can loop over the values by looping over the indices and accessing each value via the index. With general objects, you can loop over the properties and access each value via the property. While you're kind of looping over the values, you're really looping over the keys to access the values.

ES5 added several iteration helpers for objects: forEach(..), every(..) & some(..). Each of these helpers accept a function callback to apply to each element in the array, differing only in how they respond to a return value from the callback.

forEach(..) will iterate over all values in the array (whether their properties are enumerable or not?? don't know), ignoring the callback values. It essentially covers every value in the object.

every(..) will iterate over the values until the callback function hits a "falsy" value.

some(..) will iterate over the values until the callback function returns a "truthy" value.

Note that the order of iteration on objects using these iterative helpers is not consistent across environments, so don't rely on the order in any way. It's only consistent with arrays, which are looped over numerically in order.

Even better in ES6 is the for..of loop, which loops over each value of an object directly. Much simpler to think of than a forEach(..) with callbacks or whatnot.

```javascript
01|for (var v of myArray) {
02|  console.log( v );
03|}
```

Iterator Objects
----------------

Here's a fascinating look into how to create iterator objects using what we know about objects' first principles. We want an iterator object `it` which we can call `it.next()` with, and it will return the next value of the object each time. When it reaches the end, the `value` property will become `undefined` and the `done` property will become `true`. Prior to completion, the `done` property was always `false`.

```javascript
01|var myObject = {
02|  a: 2,
03|  b: 3
04|};
05|
06|Object.defineProperty( myObject, Symbol.iterator, {
07|  enumerable: false, // <-- this is up to you, do you want Symbol.iterator to be enumerable inside a for..in loop?
08|  writable: false, // <-- this is up to you, do you want Symbol.iterator's value to be changeable after this?
09|  configurable: true, // <-- set true so that you can change your mind anytime on how to configure the Symbol.iterator property
10|  value: function() {
11|    var o = this; // <-- `this` implicitly bound to the object (on line 26)
12|    var idx = 0; // index is set to 0 initially, but the function "next" provided as the return value on line 14 will increment the index everytime it is called (on line 17)
13|    var ks = Object.keys( o ); // this returns an array of properties; by looping over the array can access each property and hence access each value as well. This is what `o[ks[idx++]]` is doing on line 17
14|    return {
15|      next: function() {
16|        return {
17|          value: o[ks[idx++]],
18|          done: (idx > ks.length)
19|        };
20|      }
21|    };
22|  }
23|} );
24|
25|// iterate `myObject` manually
26|var it = myObject[Symbol.iterator]();
27|it.next(); // { value:2, done:false }
28|it.next(); // { value:3, done:false }
29|it.next(); // { value:undefined, done:true }
```

Notice how the variables o, idx & ks are much like attributes of an object in Java and the function "next" is like methods of an object that alter the attributes. You could totally create more methods like "previous" as well - just declare a new property called "previous" followed by an anonymous function and include that as the return value object of myObject[Symbol.iterator](). This is amazing, so this is how two different object paradigms can do the same thing like creating an iterator object.

    --------------------------------------
    CHAPTER 4: MIXING (UP) "CLASS" OBJECTS
    --------------------------------------

    Mostly he covers the basics of OOP and how to "emulate" those behaviors in JavaScript. Ultimately he advises that "OOP" constructs are quite brittle in JavaScript and you're better off using another design pattern.

    ---------------------
    CHAPTER 5: PROTOTYPES
    ---------------------

Objects in JavaScript have an internal property, denoted in the specification as [[Prototype]]. Almost all objects are given a non-null value for this property at the time of their creation.

Note: ES6 introduces Proxies, and everything we are about to discuss about [[Get]] & [[Put]] do not apply when Proxies come into play.

[[Get]]-ting a property
-----------------------

When you call a [[Get]] on an object property, [[Get]] looks for a property of the same name within the object. If it finds it, it returns that property's value. If it cannot be found, [[Get]] will then follow the [[Prototype]] link of the object. This process continues until either the matching property is found, or the [[Prototype]] chain ends. if no matching property is found by the end of the chain, [[Get]] returns `undefined`.

But wait? How are Prototypal chains instantiated in the first place? Observe the code below:

```javascript
var objectOne = { a: "2" };
var objectTwo = Object.create( objectOne );
var objectThree = Object.create( objectTwo );
objectThree.a; // 2
```

objectThree's prototype is objectTwo, whose prototype is objectOne, whose object prototype is Object.prototype. Ultimately, all normal objects end up with Object.prototype as their lowest level prototype.

Object.create(..) takes in one argument, which is the object to be used as the prototype when creating the new object. The prototypal chain for objectThree follows into objectTwo which follows into objectOne which is where the `a` property is finally found.

If left blank (I ASSUME) the default Object.prototype object will be used, which is how most objects have access to Object.prototype functions like forEach(..) or toString().
You can instantiate an object without a prototype by passing in `NULL` as the argument to Object.create(..), but then you'd lose access to all the default functions present in Object.prototype.

[[Put]]-ting a property
-----------------------

When you call [[Put]] on an object property with the `=` assignment operator (a la `myObject.a = someValue`), [[Put]] looks for a property of the same name within the object. If it exists, it merely changes the value of that property.

    If it doesn't exist, it will either find that property in the Prototype chain or it will not. If doesn't find the property anywhere up in the Prototype chain, it merely add that new property to the direct object. So far so good.

        If it does finds that property in the Prototype chain, one of three things will happen:

            1) If the property is writable (writable = true), the new property is added to the direct object and the prototype property is _SHADOWED_.

            2) If the property is marked as non-writable (writable = false), that means the property should not be changed and so trying to change it will either fail silently in non-strict mode or throw an error in strict mode.

            3) If the property turns out to be a setter, then the setter will be called. No new properties will be added, nor will the setter be redefined.

            If you want to shadow the prototype property in case 2 or case 3, you have to use the Object.defineProperty(..) method instead of the `=` assignment operator.

Generally shadowing methods leads to ugly explicit pseudo-polymorphism if you need to delegate between them. It's better to avoid shadowing in general as it's more complicated than it's worth (doubt?).

Implicit Shadowing
------------------

To avoid shadowing, always MAKE SURE that the property you're about to change actually exists in the direct object itself (with myObject.hasOwnProperty(..)), not in one of its prototypes. Else you could end up accidentally shadowing the the prototype property.

    When a function is invoked with a `new` in front of it, four things happen:
    1) A brand new object is created
    2) The newly constructed object is [[Prototype]]-linked
    3) The newly considered object is set as the `this` binding for that function call
    4) Unless the function returns its own alternate object, the `new`-invoked function call will return the newly constructed object (its default behaviour).

    ------------------------------
    CHAPTER 6: BEHAVIOR DELEGATION
    ------------------------------

    // more stuff goes here, I was too lazy to transcribe

================================================================================

    ==================================
    YOU DON'T KNOW JS: TYPES & GRAMMAR
    ==================================

    ----------------
    CHAPTER 1: TYPES
    ----------------

================================================================================

    ======================================
    YOU DON'T KNOW JS: ASYNC & PERFORMANCE
    ======================================

    ----------------------------------
    CHAPTER 1: ASYNCHRONY: NOW & LATER
    ----------------------------------

```javascript
01|function now() {
02|  return 21;
03|}
04|
05|function later() {
06|  answer = answer * 2;
07|  console.log( "Meaning of life:", answer );
08|}
09|
10|var answer = now();
11|
12|setTimeout( later, 1000 ); // Meaning of life: 42
```

The now chunk runs right away, as soon as you execute your program. But setTimeout(..) also sets up an event (a timeout) to happen later, so the contents of the later() function will be executed at a later time (1,000 milliseconds from now).

Any time you wrap a portion of code into a function and specify that it should be executed in response to some event (timer, mouse click, Ajax response, etc.), you are creating a later chunk of your code, and thus introducing asynchrony to your program.
