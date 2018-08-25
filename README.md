# modular-engine
A modular approach for a new game engine using a dependency injection framework google fruit.

# How to Run

Use
`conan export googlefruit inexorgame/stable`
to create a google fruit package.

Afterwards use the new experimental conan feature [workspaces](https://docs.conan.io/en/latest/developing_packages/workspaces.html):a solution to work on different conan packages in the same *workspace*.

Therefore resolve all dependencies (in the workspace)

`conan install . -if=build`

Afterwards build it by changing into the build directory and executing cmake.


`cd build && cmake .. && cmake --build .`

Then execute `app` with

`cd app`

`./app`


*You should see `Hello World` in the console here*