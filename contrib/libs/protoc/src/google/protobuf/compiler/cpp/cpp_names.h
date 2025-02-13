// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef GOOGLE_PROTOBUF_COMPILER_CPP_NAMES_H__
#define GOOGLE_PROTOBUF_COMPILER_CPP_NAMES_H__

#include <string>

#include <google/protobuf/port_def.inc>

namespace google {
namespace protobuf {

class Descriptor;
class EnumDescriptor;
class FieldDescriptor;

namespace compiler {
namespace cpp {

// Returns the unqualified C++ name.
//
// For example, if you had:
//   package foo.bar;
//   message Baz { message Qux {} }
// Then the non-qualified version would be:
//   Baz_Qux
TProtoStringType ClassName(const Descriptor* descriptor);
TProtoStringType ClassName(const EnumDescriptor* enum_descriptor);

// Returns the fully qualified C++ name.
//
// For example, if you had:
//   package foo.bar;
//   message Baz { message Qux {} }
// Then the qualified ClassName for Qux would be:
//   ::foo::bar::Baz_Qux
TProtoStringType QualifiedClassName(const Descriptor* d);
TProtoStringType QualifiedClassName(const EnumDescriptor* d);
TProtoStringType QualifiedExtensionName(const FieldDescriptor* d);

// Get the (unqualified) name that should be used for this field in C++ code.
// The name is coerced to lower-case to emulate proto1 behavior.  People
// should be using lowercase-with-underscores style for proto field names
// anyway, so normally this just returns field->name().
TProtoStringType FieldName(const FieldDescriptor* field);

// Strips ".proto" or ".protodevel" from the end of a filename.
PROTOC_EXPORT TProtoStringType StripProto(const TProtoStringType& filename);

}  // namespace cpp
}  // namespace compiler
}  // namespace protobuf
}  // namespace google

#include <google/protobuf/port_undef.inc>

#endif  // GOOGLE_PROTOBUF_COMPILER_CPP_NAMES_H__
