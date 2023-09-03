# Assignment 09

## Need of lazy()

-   lazy is used to lazy load a bundle on demand.

-   Creates a separate bundle file for the components when it is been called.

## Suspense

-   Suspense is a component required by the lazy function basically used to wrap lazy components. Multiple lazy components can be wrapped with the suspense component. It takes a fallback property that accepts the react elements you want to render as the lazy component is being loaded

-   When a file is loaded it takes some time to load into the browser but the file is rendered immediately, thus we need to wrap component in suspense to tell browser that something is missing and coming for rendering.

-   It requires a fallback component to be render in between this process.

## Error: Component Suspended while responding to synchronous input.

-   This will cause the UI to replaced with a loading indicator,

-   To fix, updates that suspense should be wrapped with startTransition.

-

## Advantages and Disadvantages

-   Advantages-

    1. Faster Initial Page Load
    2. Better Performance
    3. Reduce Bandwidth Usage
    4. Improved Caching
    5. Code Maintainability.

-   Disadvantages-

    1. Complexity
    2. Potential Bugs.
    3. Development Overhead
    4. Network Request
    5. Compatibility.
