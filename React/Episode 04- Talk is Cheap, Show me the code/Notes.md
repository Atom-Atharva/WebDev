# Episode 04: Talk is Cheap, Show me the Code!

-   Before Building an app we must do planning.

## Planning

-   We should know what to build and how to build.
-   UI Design, Layout, Wire-frame, etc.

## Inline CSS in JS

-   We create an object using JS which contains the CSS properties.
-   Not preferred way to write code.

## Props

-   Props means properties.
-   Passing a props to a functions is same as passing argument to a function.
-   When we need to make dynamic component we need to pass data as props.
-   Generally data is not passed in arguments, it is passed as JSON.
-   ### Config-driven UI (V-IMP)
    -   Front-end Design Interviews.
    -   It means our web site is driven by data.
    -   This data come from backend.
    -   UI will be according to data/config.
    -   We have written UI once and according to data it changes by its own.

#### NOTE :

-   `array.join("string")` ---> Join our array with string in between 2 entries.
-   `const { cloudinaryImageId, name, cuisines, avgRating, costForTwo } = resData?.info;` this is equivalent to resData.info.name, resData.info.cuisines, etc.
-   Try to use more Map, Reduce, Filter.
-   Whenever you are looping over any list, you have to give a key always to avoid warnings.
-   We need key because without key react will render all components which are already passed inside the looping as react doesn't know which element is added recently.
-   Using Key will reduce time complexity as it prevents everything to re-render again.
-   Do not use index as key, as it might change (NOT RECOMMENDED).
-   NOT USING KEYS (not accepted) <<<< INDEXES AS KEY <<<<<<<<<<<<< UNIQUE ID (best practice).
