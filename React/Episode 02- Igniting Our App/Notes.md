# Episode 2 Notes:

-> JSON is the configuration of npm.

-> npm is package manager.

-> There are 2 types of packages-

1. Dev Packages : Requirement in development of our app.
2. Normal Packages : Used in productions.

-> npm install -D package_name ----> Here -D denotes dev dependencies.

-> Caret(^) and Tilde(~) are used to upgrade the current version to the latest version in dependencies.

For Example:

```
"devDependencies": {
    "parcel": "^2.9.3"
}
```

^ ---> This will always upgrade to minor upgraded version.
~ ---> This will always upgrade to major upgraded version (NOT PREFERRED TO USE, MAY CAUSE CHAOS).

-> Package.json is will upgrade to minor upgrade version without reflecting changes in the json file.
-> On the other hand Package-lock.json will keep a track on the exact version that is been used.

-> When a Dependency has another dependencies this is know as transitive dependencies.

-> We don't need node_modules to push in our production or github, we can gitignore it to optimize the space and it can regenerate by package.json and package-lock.json

-> Just like npm we have npx (node package eXecute)which means executing a package. [For example: npx parcel index.html]

-> CDN links is not preferred way to bring react and reactDOM into our project because it is costlier process, also as react version increases we have to update our cdn.

# Parcel (Bundler for our Code)

-   Dev Build
-   Local Server
-   HMR = Hot Module Replacement (AutoMetic Restart Our Server)
-   File Watching Algorithm (Written in C++).
-   Caching (Faster Builds)
-   Img Optimization
-   Minification of Files on Production
-   Bundling our code
-   Compress our file
-   Consistent Hashing
-   Code Splitting
-   Differential Bundling - support older browsers
-   Diagnostic
-   Error Handling
-   HTTPs
-   Tree Shaking - Remove Unused code
-   Different dev and production bundles

-> To create production ready app, we need to remove main from the json for npx parcel build index.html to run.
-> This will create a production ready app in dist folder (compressed and bundled)

-> Browserslist NPM helps us to make our app to be compatible on certain browsers.
