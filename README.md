# ProtoBuf

## What is a protoBuf anyway?
A protobuf is a platform-neutral mechanism for serializing structured data. In simple terms, it's a method to take a struct or object, and translate that into a string of bytes that we can then transmit over a communication protocol.

## Features of a protobuf
1. Compact and Efficient - Serialize the data into a compact binary format, with less bandwidth and requirements than JSON or XML.
2. Cross-platform -> this is a simple implementation that can be easily recreated in other languages.
3. originally defined by google - can be defined by a .proto file, which serves as a schmea for how the data is structured and serialized (I should try to make mine compatible to this google implementation)
4. Versioning - new fields can be added or old fields can be deprecated without breaking compatibility.
5. Speed - Should be quick to serialize this data.

In other words, its just taking a struct and making it binary readable and transmittable.

## Debt

## [Technical Debt for this component is located here](./debt.md#TechnicalDebt)