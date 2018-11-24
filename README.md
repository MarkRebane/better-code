# better-code

This repository is inspired by a series of talks by Sean Parent in which he
describes and demonstrates a method for encapsulating runtime polymorphism known
as the Runtime Concept Idiom. This technique prevents objects that need to be
used in a polymorphic context from also being required to themselves inherit
from the shared interface. This approach is a huge boon for code reuse and
enables more code to be written in a style suitable for use in libraries. It
achieves this by treating inheritance as an implementation detail, therefore not
tightly-coupling useful code to larger data structures or frameworks. Please
visit [http://sean-parent.stlab.cc/papers-and-presentations/
](http://sean-parent.stlab.cc/papers-and-presentations/) for more information
about this and other related topics.

I created this to provide an interactive way to explore the code and read it in
a more convenient format. Also, because I personally found it was a bit
difficult to digest in slide form, simply because the examples are slightly too
long to fit on presentation slides. Sean's effort to maintain coherence between
slides was, however, greatly appreciated and very useful in creating this
repository.

The code tries to mirror the series of transformations from the talk titled
"Runtime Polymorphism" and is based on the slides from 2017-01-18. With one
transformation per commit and each commit message containing some of the key
points from the slides about that transformation. While I have tried to ensure
this is a correct representation of the code presented in the slides, and I have
compiled and run every commit using g++ 8.2.0 on Ubuntu 18.10, it's possible
that I have introduced errors along the way (sorry).

I have no affiliation to either Sean Parent or Adobe Systems. This code is
provided here in good-faith solely that it might be useful to other people and
for myself as an exercise to improve my understanding of this technique.
