# Welcome Firestorm developer!

This is the developer branch. This is where we are going to be doing all of our work. This is where you should commit your changes. Periodically I will merge this branch with the master branch. The master branch should be reserved for code that is 'stableish'.

The source code we will be working with is under the 'Source/Firestorm' folder. Headers go in the public folders and Source files go in the Private folder. This is how Unreal Engine likes to organize things, I did not set it up this way.

## Quick intro to git and GitHub

For anyone who has never used git or GitHub please keep reading, if you are a git guru, then you can either skip this section or stick around for a good laugh.

### git == GitHub?

No. `git` is the command you use to modify your `git` repository. GitHub is just a really handy website we use to manage git repositories.

A `git` repository is basically database that keeps track of changes in your code (and lots more). We will be using what is called a remote repository. Basically wherever you are in the world, you will have access to our online respository that is hosted on GitHub:

https://github.com/FirestormDevelopersOrganization/Firestorm

### How do I get the latest build?

This is pretty simple. If you are running Windows, just go to your git GUI and click the plus button. Then go to the FirestormDevelopersOrganization. Then just click on Firestorm and click clone. This will do all of the nasty work for you.

To 'update' your code to the latest code, just hit the sync button in the upper right corner of the screen, it will update your code. Just recompile the code and you should be good to go.

### What are branches?

If you are a developer, you will be working in our `dev` branch. This branch is for code that we are currently writing and testing out. When code becomes more stable, I will move it to the `master` branch or just create a whole new branch all together.

I created a `base` branch before I even compiled the code. I did this to make sure we have quick access to all of the original files that came with Unreal Engine. 

### I changed something and my repository is messed up, what do I do?

Right click your project, then open in Git Shell. You will then see a shell window open up. Make sure you are on the correct branch, you probably need to do:

```
git checkout dev
```

Now we will reset the repo, WARNING: this will destroy all of your changes!!

```
git reset --hard HEAD
```

to reset to a specific commit, use `git log` to find the commit you want, and then instead of HEAD use the SHA-1 hash of the commit.

### I have code changes that I think should go into the remote repository.

Before anything, commit all of your changes by using `commit -a` in the terminal. Then a notepad window will popup, enter a message and then save and close the window.

At this point, you should make sure your `git` is configured properly and that you are in the Developers group for the Firestorm project on GitHub. If you did not send me your username, you are not in the group.

Then you should do a `git pull` on your repository. This will take the most up to date code in the repository and merge it into your code. On your machine you now have the most up to date repository. All a `git pull` does is makes sure your repository is up to date.

Now you have to upload your code! Just simply do a `git push -u origin dev` to upload your code to the dev branch.

Once you do your push request, the code in the respository should be up to date!

Thanks for your contributation!

## Documentation

I know most people really hate documentation but in this case we have to document as much as possible. We have a lot of options for documentation, but I think that most people probably use [Doxygen](www.doxygen.org). It is pretty straight forward and I think it will be easy to stick to. I will do periodic document builds and add them on GitHub (under the wiki section probably).

Everyone should try to do some house cleaning in respect to keeping documentation clean and up to date. Documentation is a once every minute couple of minutes sort of thing, not a once a week for 3 hours sort of thing. I don't want to have to go through all of your code and do proper commenting, so please keep it clean and up to date!

## Our Objectives

At the last meeting (on July 25th) we talked about a couple of different things we wanted to implement in code. Here is a short summary of some of the things taht we talked about:

1. Character Personality: each character reacts to the environment based on their personality
  * Ex) A passenger sneezes on another passenger, depending on the recipiant's personality, they will react accordingly (probably with anger).
2. Absolute story events: These are events that must occur in each simulation, there is nothing that the play can do to stop these events
  * Ex) If the waiter is supposed to bring you coffee when you wake up, another passenger sneezing on our waiter will not hinder her (she will make it to the table no matter what).
3.  Weird stuff starts happening; when the player starts getting closer to realising the greater truth, the game starts getting slightly 'weird'.
  * Ex) Maurice had an idea that at some point in the game, your charater sees someone reading a newspaper sitting in a seat that was not there before. They are wearing a lab coat and they look suspicious.

Please add more objectives here, I know I missed a couple of important ones!

## Implementing our objectives

First I think it is important to get the structure of our program worked out before we start actually implementing stuff. Let's start with implementing the characters in the world!

### Characters in our world

In Unreal Engine, there is a class called ACharacter (or simply just Character). This class is used to represent an actual character in the game. We should extend the Character class and call it something like CharacterBase. This CharacterBase class will have the following functions:

1. It should have methods called `sneeze()` and `wasSneezedOn()` for example. When other characters sneeze on our character, they will call our character's `wasSezedOn()`. Likewise, when our character calls `sneeze()`, our `sneeze()` method will call all of the `wasSneezedOn()` functions of characters around us (or directly in front of us).
2. It should act as a world helper. By this I mean we should have some helper functions like `getCharactersWithinDistance(int centimeters)` that will return all characters within the specifed distance. We should also have another function like `pickObjects()` which will return a list of 'picked' objects. If you are not familiar with what `pick` means in the 3D world, it is when you are looking at something and you want to 'click' on it. This selective action is called picking. Another useful method might be something like `walkToLocation(float x, float y)`, the character will start walking to the x,y location parameter.
3. It should have an instance of `CharacterPersonality`. `CharacterPersonality` is the class that will contain all of the attributes of the personality of each character. Some examples of these attributes would be anger or patience. If your patience runs out, you are more irritable. When your anger gets too high, you get angry and make rash decisions. 

Our class heirarchy is probably going to end up looking something like this:

APawn
  + ACharacter
    + BaseCharacter
      + MainCharacter << Our actual character that we play
      + StoryCharacter << Characters that are crutial to the game perhaps
      ...
    + Janitor << For example, perhaps all Janitors are a bit more tense than the other characters
    + CoupleMan
    + CoupleWoman << For exmple, the `CoupleMan` and `CoupleWomen` will want to stay close to eachother.
    ...

Please feel free to add stuff here, this is probably going to be our most documented section.

Right now I think we are just trying to get the structure down. We will probably start doing some actual coding next week.

### Absolute story events

How we go about programming this is probably left for later. When the story is actually written, then we will know more on what kind of structure we should use for this part of the game.

We should probably come up with a set of options for each characters when they are 'late' or 'not on schedule' to reaching an objective on time. Being 'teleported' to their objective when the character isn't looking will probably be a quick fix.

### Weird stuff?

This is probably best left for later as well. We are pretty bottle-necked with the story right now. When we know more of the story, we will start conjuring up our 'twilight zone events'.

I think this is another place for us to really shine here, we can can impement some pretty freaky stuff here.

## Conclusion

Feel free to edit this file guys, add your own ideas and comments!

If you are very interested in contributing to this project, start making commits! It would be great to gauge how many programmers will be really helping us on this project!