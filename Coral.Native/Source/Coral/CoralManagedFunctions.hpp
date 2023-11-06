#pragma once

#include "Core.hpp"
#include "NativeString.hpp"

namespace Coral {

	struct UnmanagedArray;
	enum class AssemblyLoadStatus;
	class ManagedObject;
	enum class GCCollectionMode;
	enum class ManagedType;
	class ManagedField;

	using SetInternalCallsFn = void(*)(void*, int32_t);
	using CreateAssemblyLoadContextFn = int32_t(*)(NativeString);
	using UnloadAssemblyLoadContextFn = void(*)(int32_t);
	using LoadManagedAssemblyFn = int32_t(*)(int32_t, NativeString);
	using GetLastLoadStatusFn = AssemblyLoadStatus(*)();
	using GetAssemblyNameFn = NativeString(*)(int32_t);

#pragma region TypeInterface

	using GetAssemblyTypesFn = void(*)(int32_t, TypeId*, int32_t*);
	using GetTypeIdFn = void(*)(NativeString, TypeId*);
	using GetFullTypeNameFn = NativeString(*)(TypeId);
	using GetAssemblyQualifiedNameFn = NativeString(*)(TypeId);
	using GetBaseTypeFn = void(*)(TypeId, TypeId*);
	using IsTypeSubclassOfFn = Bool32(*)(TypeId, TypeId);
	using IsTypeAssignableToFn = Bool32(*)(TypeId, TypeId);
	using IsTypeAssignableFromFn = Bool32(*)(TypeId, TypeId);
	using GetTypeMethodsFn = void(*)(TypeId, ManagedHandle*, int32_t*);
	using GetTypeFieldsFn = void(*)(TypeId, ManagedHandle*, int32_t*);
	using GetTypePropertiesFn = void(*)(TypeId, ManagedHandle*, int32_t*);
	using GetTypeAttributesFn = void (*)(ManagedHandle, TypeId*, int32_t*);
	using GetTypeManagedTypeFn = ManagedType(*)(TypeId);

#pragma endregion

#pragma region MethodInfo
	using GetMethodInfoNameFn = NativeString(*)(ManagedHandle);
	using GetMethodInfoReturnTypeFn = void(*)(ManagedHandle, TypeId*);
	using GetMethodInfoParameterTypesFn = void(*)(ManagedHandle, TypeId*, int32_t*);
	using GetMethodInfoAccessibilityFn = TypeAccessibility(*)(ManagedHandle);
	using GetMethodInfoAttributesFn = void(*)(ManagedHandle, TypeId*, int32_t*);
#pragma endregion

#pragma region FieldInfo
	using GetFieldInfoNameFn = NativeString(*)(ManagedHandle);
	using GetFieldInfoTypeFn = void(*)(ManagedHandle, TypeId*);
	using GetFieldInfoAccessibilityFn = TypeAccessibility(*)(ManagedHandle);
	using GetFieldInfoAttributesFn = void(*)(ManagedHandle, TypeId*, int32_t*);
#pragma endregion

#pragma region PropertyInfo
	using GetPropertyInfoNameFn = NativeString(*)(ManagedHandle);
	using GetPropertyInfoTypeFn = void(*)(ManagedHandle, TypeId*);
	using GetPropertyInfoAttributesFn = void(*)(ManagedHandle, TypeId*, int32_t*);
#pragma endregion

#pragma region Attribute
	using GetAttributeFieldValueFn = void(*)(ManagedHandle, NativeString, void*);
	using GetAttributeTypeFn = void(*)(ManagedHandle, TypeId*);
#pragma endregion

	using CreateObjectFn = ManagedObject(*)(NativeString, Bool32, const void**, const ManagedType*, int32_t);
	using InvokeMethodFn = void(*)(void*, NativeString, const void**, const ManagedType*, int32_t);
	using InvokeMethodRetFn = void(*)(void*, NativeString, const void**, const ManagedType*, int32_t, void*);
	using InvokeStaticMethodFn = void (*)(TypeId, NativeString, const void**, const ManagedType*, int32_t);
	using InvokeStaticMethodRetFn = void (*)(TypeId, NativeString, const void**, const ManagedType*, int32_t, void*);
	using SetFieldValueFn = void(*)(void*, NativeString, void*);
	using GetFieldValueFn = void(*)(void*, NativeString, void*);
	using SetPropertyValueFn = void(*)(void*, NativeString, void*);
	using GetPropertyValueFn = void(*)(void*, NativeString, void*);
	using DestroyObjectFn = void(*)(void*);

	using CollectGarbageFn = void(*)(int32_t, GCCollectionMode, Bool32, Bool32);
	using WaitForPendingFinalizersFn = void(*)();

	struct ManagedFunctions
	{
		SetInternalCallsFn SetInternalCallsFptr = nullptr;
		LoadManagedAssemblyFn LoadManagedAssemblyFptr = nullptr;
		UnloadAssemblyLoadContextFn UnloadAssemblyLoadContextFptr = nullptr;
		GetLastLoadStatusFn GetLastLoadStatusFptr = nullptr;
		GetAssemblyNameFn GetAssemblyNameFptr = nullptr;

#pragma region TypeInterface

		GetAssemblyTypesFn GetAssemblyTypes = nullptr;
		GetTypeIdFn GetTypeIdFptr = nullptr;
		GetFullTypeNameFn GetFullTypeNameFptr = nullptr;
		GetAssemblyQualifiedNameFn GetAssemblyQualifiedNameFptr = nullptr;
		GetBaseTypeFn GetBaseTypeFptr = nullptr;
		IsTypeSubclassOfFn IsTypeSubclassOfFptr = nullptr;
		IsTypeAssignableToFn IsTypeAssignableToFptr = nullptr;
		IsTypeAssignableFromFn IsTypeAssignableFromFptr = nullptr;
		GetTypeMethodsFn GetTypeMethodsFptr = nullptr;
		GetTypeFieldsFn GetTypeFieldsFptr = nullptr;
		GetTypePropertiesFn GetTypePropertiesFptr = nullptr;
		GetTypeAttributesFn GetTypeAttributesFptr = nullptr;
		GetTypeManagedTypeFn GetTypeManagedTypeFptr = nullptr;

#pragma endregion

#pragma region MethodInfo
		GetMethodInfoNameFn GetMethodInfoNameFptr = nullptr;
		GetMethodInfoReturnTypeFn GetMethodInfoReturnTypeFptr = nullptr;
		GetMethodInfoParameterTypesFn GetMethodInfoParameterTypesFptr = nullptr;
		GetMethodInfoAccessibilityFn GetMethodInfoAccessibilityFptr = nullptr;
		GetMethodInfoAttributesFn GetMethodInfoAttributesFptr = nullptr;
#pragma endregion
		
#pragma region FieldInfo
		GetFieldInfoNameFn GetFieldInfoNameFptr = nullptr;
		GetFieldInfoTypeFn GetFieldInfoTypeFptr = nullptr;
		GetFieldInfoAccessibilityFn GetFieldInfoAccessibilityFptr = nullptr;
		GetFieldInfoAttributesFn GetFieldInfoAttributesFptr = nullptr;
#pragma endregion

#pragma region PropertyInfo
		GetPropertyInfoNameFn GetPropertyInfoNameFptr = nullptr;
		GetPropertyInfoTypeFn GetPropertyInfoTypeFptr = nullptr;
		GetPropertyInfoAttributesFn GetPropertyInfoAttributesFptr = nullptr;
#pragma endregion

#pragma region Attribute
		GetAttributeFieldValueFn GetAttributeFieldValueFptr = nullptr;
		GetAttributeTypeFn GetAttributeTypeFptr = nullptr;
#pragma endregion

		CreateObjectFn CreateObjectFptr = nullptr;
		CreateAssemblyLoadContextFn CreateAssemblyLoadContextFptr = nullptr;
		InvokeMethodFn InvokeMethodFptr = nullptr;
		InvokeMethodRetFn InvokeMethodRetFptr = nullptr;
		InvokeStaticMethodFn InvokeStaticMethodFptr = nullptr;
		InvokeStaticMethodRetFn InvokeStaticMethodRetFptr = nullptr;
		SetFieldValueFn SetFieldValueFptr = nullptr;
		GetFieldValueFn GetFieldValueFptr = nullptr;
		SetPropertyValueFn SetPropertyValueFptr = nullptr;
		GetPropertyValueFn GetPropertyValueFptr = nullptr;
		DestroyObjectFn DestroyObjectFptr = nullptr;

		CollectGarbageFn CollectGarbageFptr = nullptr;
		WaitForPendingFinalizersFn WaitForPendingFinalizersFptr = nullptr;
	};

	inline ManagedFunctions s_ManagedFunctions;

}
