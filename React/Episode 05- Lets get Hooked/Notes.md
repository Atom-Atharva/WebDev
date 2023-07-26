# Episode 05: Lets get Hooked!

## Why React

-   All thing react can do can be done using HTML, CSS, JS
-   React make developer experience easy as it makes developer to code less and do more things.
-   We should make separate files for separate components.
-   React is fast because it can do fast and efficient DOM manipulation.

## Food Ordering App--

```
/**
 *
 * Header
 *  - Logo
 *  - Nav Items
 * Body
 *  - Search
 *  - Restaurant Container
 *      - Restaurant Card
 *          - img
 *          - name of Rest, star Rating, Cuisine, delivery time.
 * Footer
 *  - Copyright
 *  - Links
 *  - Address
 *  - Contact
 *
 */
```

-   Never Ever put hardcoded data, string, url inside component file.

-   Two Type of Exports and Imports-

    1.  Default Export: Only 1 default export per file,

               export default Component;
               import Component from path;

    2.  Named Export: Export Multiple things in single file (SEE constants.js).

                export const Component;
                import {Component} from path;

-   Two Type of Variables-

    1. Normal JS Variable

    2. State Variable - Super Powerful Variables
        - For this we use hooks which is known as use state.

## React Hooks

-   Hooks are just a normal JS utility function which comes with super powers.
-   We need to import these functions from React as Named Import (See Body.js).
-   Two most important hooks-
    -   useState() : Super powerful state variables in React and it keeps the UI in sync with the variable.
    -   Normal Variable will not update UI on its change.
    -   Whenever a state variable updates React re-render the components this is known as RENDER.
    -   useEffect() :

## Super Powers Of React

-   ### Reconciliation Algorithm (React Fiber):
    -   Also known as React Fiber (React 16).
    -   Whenever you create UI, React creates Virtual DOM of it.
    -   Virtual DOM is representation of actual DOM (See app.js).
    -   Virtual DOM is an Object.
    -   DIFF Algorithm : Find out the difference between old and new Virtual DOM.
    -   After finding differences React updates the DOM / Re-render the component.
