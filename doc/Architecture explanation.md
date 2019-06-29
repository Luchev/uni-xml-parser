# Architecture of XML-parser

For class structure, inheritance tree and dependencies see the UML diagram under `doc/UML/`

The backbone of the program is the the class `XmlBuilder` which connects all the other classes to build an XML tree from a given stream (file or string stream).

**XmlElement** is an abstract class. It plays the role of an interface for the different XML element types.

**XmlElementEmpty** represents the self closing tags `<img src=".." />`

**XmlElementSpecial** represents the header tags `<?xml ... ?>`

**XmlElementContent** represents the text between two tags `<a>CONTENT</a>`

**XmlElementDefault** represents the normal open/close tag, which can contain child elements as well as content. Because it can contain a mixture of both the content is an "element" of its own. This way it can be a part of an array of child elements thanks to polymorphism. This allows to parse successfully the following complex XML for example:

```html
<html>
   <body>
      <h2 title="I'm a header">The title Attribute</h2>
      <p title="I'm a tooltip">
          Point this <span style="color:red;">paragraph</span>
      </p>
   </body>
</html>
```

Here `<p>` contains a mixture of tags and content so using something like XmlElementContent to be a valid "element" is a nice solution for the problem.

**XmlConfig** is a singleton holding the configuration for the parser

**CharacterSet** is a static class providing methods for checking strings and characters for being part of a certain set of characters. For example check if a string is valid XML name, or if string has white spaces, etc.

**StringExtension** is a static class providing methods to extend the normal functionality of `std::string` with trim methods.