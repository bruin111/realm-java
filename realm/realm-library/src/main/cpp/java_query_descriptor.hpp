/*
 * Copyright 2016 Realm Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef JAVA_QUERY_DESCRIPTOR_HPP
#define JAVA_QUERY_DESCRIPTOR_HPP

#include <jni.h>

namespace realm {

namespace jni_util {
class JavaClass;
}

namespace _impl {

// For converting a Java QueryDescriptor object to realm::SortDescriptor or realm::DistinctDescriptor.
//
// This class is not designed to be used across JNI calls. So it doesn't acquire a reference to the given Java object.
// We don't hold a pointer to the native Sort/DistinctDescriptor in the Java object like normally we do, because the
// ObjectStore always consumes the descriptor by calling the move constructor. Holding an empty descriptor at Java level
// thus doesn't make much sense and causes problems with memory management.
class JavaQueryDescriptor {
public:
    JavaQueryDescriptor(JNIEnv* env, jobject query_desc_obj)
        : m_env(env)
        , m_query_desc_obj(query_desc_obj)
    {
    }

    JavaQueryDescriptor(const JavaQueryDescriptor&) = delete;
    JavaQueryDescriptor& operator=(const JavaQueryDescriptor&) = delete;
    JavaQueryDescriptor(JavaQueryDescriptor&&) = delete;
    JavaQueryDescriptor& operator=(JavaQueryDescriptor&&) = delete;

    // Prevent heap allocation
    static void *operator new     (size_t) = delete;
    static void *operator new[]   (size_t) = delete;
    static void  operator delete  (void*)  = delete;
    static void  operator delete[](void*)  = delete;

    realm::SortDescriptor sort_descriptor() const noexcept;
    realm::DistinctDescriptor distinct_descriptor() const noexcept;
    realm::IncludeDescriptor include_descriptor() const;

private:
    JNIEnv* m_env;
    jobject m_query_desc_obj;

    realm::Table* get_table_ptr() const noexcept;
    std::vector<std::vector<size_t>> get_column_indices() const noexcept;
    std::vector<std::vector<LinkPathPart>> get_linkpath_indices() const;
    std::vector<bool> get_ascendings() const noexcept;

    jni_util::JavaClass const& get_query_desc_class() const noexcept;
};

} // namespace _impl
} // namespace realm
#endif // JAVA_QUERY_DESCRIPTOR_HPP
