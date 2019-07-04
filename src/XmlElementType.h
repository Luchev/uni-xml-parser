#pragma once
/** \file */

/** \enum XmlElementType
 * Specify the different type of XML element
 */
/** \var XmlElementType::Empty
 * Represents a self-closing tag
 */
/** \var XmlElementType::Special
 * Represents a header tag
 */
/** \var XmlElementType::Default
 * Represents a normal open-close tag with its children
 */
/** \var XmlElementType::Content
 * Represents the text between an open and close tags
 */
enum class XmlElementType {
    Empty,
    Special,
    Default,
    Content
};
