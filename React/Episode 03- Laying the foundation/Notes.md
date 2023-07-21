# Episode 03: Notes

-   To start a project see script from package.json and enter npm run scriptName inside the terminal.
-   Npm start is same as npm run start but npm run build doesn't have similar call, start is special keyword.
-   Since createElement is too much work, so to minimize work we use JSX.

## JSX

-   It just make our life easy.

-   JSX and React are both different things.

-   JSX is just a Syntax.

-   React tries to merge HTML and JS together.

-   Similarly JSX is a convention where we can merge HTML and JS together.

-   JSX is not HTML inside JS, Rather it is HTML-like syntax inside JS.

-   JSX is not a valid JS, JS engine doesn't understand JSX. JS engine understand only ES-6.

-   Parcel is responsible (Parcel takes helps of babel (JS Compiler)) for the transpiled (converted to the code which react can understand) the code before it reaches JS Engine.

-   Babel converts JSX into React.createElement which is object and using reactDOM it is converted to HTML.

-   Attribute in JSX is always in Camel-Casing.

-   Multi-line JSX is wrapped inside brackets.

-   JSX also helps to escape malicious data when written inside {...} i.e, prevents cross site scripting attacks on your computer.

-   JSX expression must have only one parent element.

## React Component

-   ### Class Based Component (OLD)

-   ### Functional Component (NEW)
    -   React Functional Component is just a normal JS function that return a piece of JSX code.
    -   Component is rendered as tag (See Code).
    -   Component Composition - When we use components inside component.
    -   We can inject any JS into our JSX using {}.
    -   We can mix and match anything inside anything (See Code).
    -   React Fragments - Solves the problem of only one parent element (See Code), it behaves as an empty tag. OR we can use just <> empty tags.
