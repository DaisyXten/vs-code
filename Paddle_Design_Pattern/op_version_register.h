// https://stackoverflow.com/questions/31224643/variant-vs-inheritance
// Let's suppose I'm writing a compiler for some programming language. It is common to use abstract syntax tree (AST) as an internal representation. I can see two possible ways to design it:
//
// using boost::variant
// using inheritance
// As hierarchy of nodes is fixed - boost::variant will suffice.
//
// My question is what are the advantages and disadvantages of each approach from points of maintability and runtime efficiency?
//
// Largely opinion based. I'd use variants. But that's because I don't mind the visitors that come with it. And also because Boost Spirit happens to work very very nicely with them. But then again, YMMV and you might not have this "accidental" benefit of library compatibility – sehe Jul 4 '15 at 21:41
// I do no agree this question is opinion based at all. It is about best practices when designing the code. Nothing of what has been asked here cannot be measured, both the advantages and the disadvantages of each of the two approaches can be analyzed from a technical point of view. Another great question closed for no reason.
//
// Using boost::variants will work, but will require you to use visitor pattern extensively to exploit the content of a variant object. If later you extend the number of types used in your variant, you'll have to maintain all the visitors that you've implemented.
//
// With inheritance, you have the advantage of being able to use polymorphism. Later extension will be straightforward : simply derive one of the existing base and override the polymorphic functions, without touching the rest of the code.
//
//
// I guess first is better when new operations are added often and new types are added rarely, and the second is better when new operations are added rarely and new types are added often? – justanothercoder Jul 4 '15 at 20:16
// 1
// @justanothercoder Interesting thought ! The first is better if the types are rather unrelated, and it would be difficult to design a common base. In this case new operations are indeed easier to add for variant. –
