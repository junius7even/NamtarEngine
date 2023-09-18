# Summary
A custom game engine(WORK IN PROGRESS!) for 2D games using the sfml library written using a Data-Oriented approach. In the midst of creating a new repository for my fourth project written using the sfml library, I got tired of writing the exact same code needed to run a game project(at least, in my naive implementations), so I decided to create my own engine tailored for 2D graphics projects using SFML. 

Much of what I've written here is learned from the great book "Game Engine Architecture" and various guidances from online communities; seeing the implementations of giants(like entt and Unity's ECS) also helped shape a great ton of how this engine is structured and written.

# Acknowledgements
This engine is not a true ECS in the sense that it still relies on objects and OOP principles where GameObjects implemented do not solely bear data.

# Architecture
The Engine class is treated as the World since no need has currently come up to distinguish the two in my case. The Engine class owns the component pool and gameObject pools which contain independent components that can attach to GameObjects, and the GameObjects themselves respectively. 

## Creation of GameObjects and Components
The Engine stores "scene" data that will be read on each bootup in JSON. The JSON is parsed and contains all the information on GameObjects and their respective components. This prompts the creation of the respect types of components and gameObjects.

- At creation time, both gameObjects and components are assigned a unique ID given by the IDManager, which when a specific component/gameObject is deleted, pushes the unique ID on a stack and prioritizes the distribution of stored IDs rather than incrementing.
- Components are createed by using a Map from string(name) to designated typeID. This will decide how the object is created using what parts of the parsed JSON as parameters and such.

This current implementation of data storage and reading isn't the greatest. First of all, the Engine stores "scene" data in a JSON object, which is then parsed and handled by the famous single header NlohmanJSON library.
- With the existence of SIMDJson, the speed of which those files can be parsed is orders higher(4 times).
- Other more efficient storage systems exist (I have yet to explore those options since that was not a priority at the time).

## Storage method
In an attempt to utilize cache locality, the componentPool and gameObjectPool are **vectors** of pointers their respective stored classes. 

The gameObjectPool stores created gameObjects, where the ID of each gameObject corresponds to their location in the gameObjectPool vector. 

## Logic execution
At the start of each initialization(run) process of the Engine, the "Start" function on all active Components will be called.

Each frame, Update and LateUpdate, which provide two orders of execution(for example, UI modifying instructions executing after transform manipulations), are called whereas physics lives on a different thread.

## So, where does the scripting come in?
Unfortunately, since I haven't got to building the UI and an efficient system to recognize and integrate new components inheriting from the Component class, so everything has to be done by manually adding those into the Engine.cpp file directly as well as hand writing into a JSON scene file. I intend to start working on it once I decide on what direction the Engine architecture should head in as well as a better storage method.
