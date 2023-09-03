# Episode 09: Optimizing our Code

## Single Responsibility Function

-   App is divided into small modules.
-   Each module responsible for only one function.
-   Easy to test each module.
-   Reusability of each component.
-   Code becomes readable, maintainable, testable.

## Custom Hooks

-   It is not mandatory, but it will make your code look more readable, modular, reusable.
-   See RestaurantMenu.js and useOnlineStatus.js
-   All custom hooks are inside utils.

## How to write custom hooks

1.  Finalize the contract.

    -   INPUT AND OUTPUT OF HOOK.

2.  Start Hook name with use.

    -   it is recommended not mandatory, makes our code understandable, and avoid linter errors.

## Optimizing Our App

-   We know parcel is used to bundle our code.

-   It generate a single file in our app.

-   Problem with single file in our app is that it takes a lot of time to load, size of file will increase, productivity becomes slow.

-   We need to make small bundles for the above and this process is known as:

    1. Chunking
    2. Code Splitting
    3. Lazy Loading
    4. Dynamic Bundling
    5. On Demand Loading
    6. Dynamic Import

-   SEE App.js

-   On lazy import the error page is rendered as js file takes some time to load.

-   For this we have suspense from react we need to wrap the component with suspense with fallback (TO SHOW BETWEEN LOADING) which is not yet known.
