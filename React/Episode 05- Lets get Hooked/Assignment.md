# Assignment 05

## Named Export, Default Export, \* as Export

-   Named Export is used when multiple exports from same component file is done.
-   Default Export when single function is exported.
-   {\*} as export when we need to export everything without mentioning name of every function.

## Importance of Config.js File

-   Config.js file help developer to configure their app in XML block instead of hard-coding values inside scripts or in JSON obj.
-   The XML can be embedded inside an HTML document or in a separate XML file.
-   The configuration block may contain strings, numbers, arrays and HTML.

## React Hooks

-   Hooks are just a normal JS utility function which comes with super powers.
-   We need to import these functions from React as Named Import (See Body.js).
-   Two most important hooks-
    -   useState() : Variable sync with UI.
    -   useEffect() : Ability to perform side effects from a function component.

## useState Hook

-   Super powerful state variables in React and it keeps the UI in sync with the variable.
-   Normal Variable will not update UI on its change.
-   Whenever a state variable updates React re-render the components this is known as RENDER.
