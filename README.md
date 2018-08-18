# modular-engine
A modular approach for a new game engine using a dependency injection framework google fruit.

# How to Run

Use
`cd googlefruit && conan export inexorgame/stable && cd ..`
to create a google fruit package.

Afterwards create a build folder and change into that folder.

`mkdir build && cd build`

Then install the dependencies with

`conan install .. --build missing`

and build it with

`conan build ..`

Then execute it with

`cd bin`

`./modular`


