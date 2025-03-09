if(NOT CMAKE_DOTNET_SDK)
  set(CMAKE_DOTNET_SDK "Microsoft.NET.Sdk")
endif()

if(NOT CORAL_DOTNET_VERSION)
  set(CORAL_DOTNET_VERSION "net8.0")
endif()

if(NOT CORAL_CSHARP_FLAGS)
  set(CORAL_CSHARP_FLAGS "/langversion:12")
endif()

set(CMAKE_DOTNET_TARGET_FRAMEWORK ${CORAL_DOTNET_VERSION})
set(CMAKE_CSharp_FLAGS ${CORAL_CSHARP_FLAGS})
set(CMAKE_VS_NUGET_PACKAGE_RESTORE ON)

project(CoralManaged
  VERSION 1.0.0
  DESCRIPTION "C++/C# wrapper around the .NET CoreCLR library, the purpose of Coral is to provide a native interface similar to Mono, but in a more modern style, and using .NET Core instead of .NET Framework "
  HOMEPAGE_URL "https://github.com/StudioCherno/Coral"
  LANGUAGES CSharp
)

set(TARGET_NAME Coral.Managed)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/**.cs
)

add_library(${TARGET_NAME} SHARED ${SRC_FILES})
add_library(CoralManaged ALIAS ${TARGET_NAME})

target_include_directories(${TARGET_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/Source
)

target_compile_options(${TARGET_NAME} PUBLIC "/unsafe")

set_target_properties(
  ${TARGET_NAME} PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VS_GLOBAL_RootNamespace "Coral.Managed"
  VS_GLOBAL_EnableDynamicLoading "true"
  VS_GLOBAL_ResolveNuGetPackages "true"
  VS_GLOBAL_Nullable "enable"
  VS_GLOBAL_RootNamespace "Coral.Managed"
  VS_PACKAGE_REFERENCES " " # we need this to force nuget restore before build !!!
  VISIBILITY_INLINES_HIDDEN YES
  VERSION "${PROJECT_VERSION}"
  SOVERSION "${PROJECT_VERSION_MAJOR}"
  OUTPUT_NAME "Coral.Managed"
)