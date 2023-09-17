# Episode 13: Time for the TEST

## Manual Testing

-   Testing done manually by developer.
-   Not an efficient way to test a component.
-   Single line of code can bring bugs anywhere inside our app.

## Types of Testing (developer)

-   Unit Testing : Test React Component in isolation (Testing small component of application).
-   Integration Testing : Testing the integration of the components (Test the flow of the action in our react application)
-   End to End Testing (E2E Testing) : From User Landing onto the page till leaving the page, i.e, user flows across the application are being tested.

## React Testing Library

-   Builds on top of DOM Testing Library.
-   Create React App already have testing library integrated to it, in parcel we have to integrate it.
-   JEST: Delightful JS Testing Framework with a focus on simplicity.
-   React Testing Library uses JEST behind the scenes.
-   To Get Started:

    1. First install react testing library
    2. Install Jest Testing Framework
    3. Install additional libraries for babel.
    4. Configure Babel. (Now the parcel config will clash with jest config for babel).
    5. Change behavior of parcel towards babel (Disable Default Babel Transpilation of Parcel) (SEE .parcelrc file).
    6. Jest Configuration (npx jest --init)
    7. Install JSDOM library.

-   To Run Our Test Cases --> npm run test (SEE package.json)

-   Test environment which will be used is jsdom: it is used to run test cases for our application.
-   JSDOM is not a browser but it is like a browser which give features of the browsers.

## Writing Test Cases

-   See sum.js
-   Either file inside `__test__` or file with name `example.spec|test.js`
-   `__`= dunder method (Reserve Characters for test files)
-   See sum.test.js
-   Should Contain assertion.

## Unit Testing

-   To make jsx work inside our test case we need to install @babel/preset-react, this helps our react code to be converted into normal html code.

-   Add this to our babel config

-   Add another library @testing-library/jest-dom (-D)

-   In short:

    1. Render Something
    2. Querying Something
    3. Assert Something

-   Group Multiple Test Cases we use describe (See contact.test.js).

-   test is also called it.

-   See Header.test.js for some additional details (link,browser router).

-   See RestaurantCard.test.js from props and Higher Order Functions.

## Integration Testing

-   When multiple components work together to perform test on some features.

-   See Search.test.js --> Fetch
-   npm run watch-test --> jest --watch (LIKE Hot Module Reloading).

-   Whenever there is a state update we need to wrap component render inside act() from react-dom/test-utils;

## Some useful Functions

-   beforeAll : Runs before all test cases on that file.
-   beforeEach : Runs before every test case on that file.
-   afterAll : Runs after all test cases on that file.
-   afterEach : Runs after every test case on that file.

## Cart Flow Test Cases

-   See Cart.test.js

## Coverage of Test Cases--

-   Coverage should be greater than 80-85%

-   Check detailed coverage analysis on coverage folder --> reports --> index.html

# Assignment

## Enzyme

-   JS Testing Utility for React that makes it easier to test your React Components output.

-   Manipulate, traverse and in some ways simulate runtime given the output.

-   The library allows us to use 3 different ways of rendering React components in our tests:

    1. Shallow Rendering
    2. Full DOM Rendering
    3. Static Rendering

-   Enzyme is dependent on React internals, so apart from the library itself, we need to install an Adapter that is compatible with the version of React in the project.

## RTK over Enzyme

-   The React Testing Library is a very light-weight solution for testing React components. It provides light utility functions on top of react-dom and react-dom/test-utils, in a way that encourages better testing practices.

-   RTL provides only one way of rendering React components which is "render" - equivalent to Enzyme's "mount

-   When using React Testing Library, we are working on rendered DOM nodes, so we can write tests that behave as the user would. React Testing Library is testing the UI from the "outside", so when a new version of React is released, there is no need to make any changes in the library source code.

-   React Testing Library focuses more on testing the components in a way the user would use them.
