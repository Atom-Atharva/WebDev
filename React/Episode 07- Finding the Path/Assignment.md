# Assignment : 07

## Various Ways to add images into our App

-   Import file in javascript and use it in img tag as src.

```
    import house from './house.jpg';

    function House(){
        return (
            <img src = {house} alt="House Img" />
        );
    }
```

-   Images can be inserted using required keyword into our component.

```
    function House(){
        return (
            <img src={require('./house.jpg')} alt="House Images" />
        );
    }
```

-   Images directly loaded from network

```
    function House(){
        return (
            <img src={'https://....'} alt="House Images" />
        );
    }
```

-   Images scalable vector graphic (SVG) files, directly as React Component.

```
    import {ReactComponent as Logo} from './logo.svg';

    function House(){
        return (
            <Logo />
        );
    }
```

## console.log(useState())

-   It will print array of size 2 which contains:
    1. Current State Value.
    2. Function to update the state value.

## useEffect with no dependency array

-   useEffect will be called every time it will render.

## SPA

-   SPA : Single Page Application.
-   Entire application is contained with in a single web page
-   It will dynamically updated and manipulated in response to user actions or events without the need to reload the entire page.

## Diff between client side routing and server side routing.

### Client Side Routing:

-   Offer faster page load improve performance.

-   Initially html page is usually a minimal shell that loads the required javascript and setup the client site routing, rendering components and fetching of data happens on client side.

-   Request to the server is prevented when user click a link, hence no page refresh even when the URL changes.

### Server Side Routing:

-   In server side routing the initial html page sent by the server already contains the rendered content and subsequent request trigger new server response.

-   Server-side routing involves the server being responsible for managing the routing and generating the HTML for each requested URL. When a user clicks on a link or enters a URL, the browser makes a request to the server, which responds by rendering and sending the relevant HTML page.

-   In server side routing when the user navigates to a new page, the old page is completely discarded and the HTML of the new page is loaded or When a user clicks on a link on a webpage, another whole page is loaded and rendered onto the screen.

-   In server side routing Initial load time is often faster since only the necessary content is sent by the server.
