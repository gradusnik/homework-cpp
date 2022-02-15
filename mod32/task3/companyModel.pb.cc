// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: companyModel.proto

#include "companyModel.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
constexpr CompanyModel::CompanyModel(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : juristicaddr_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , name_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , sortofactivity_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , estyear_(0)
  , exteconomactivity_(false){}
struct CompanyModelDefaultTypeInternal {
  constexpr CompanyModelDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~CompanyModelDefaultTypeInternal() {}
  union {
    CompanyModel _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT CompanyModelDefaultTypeInternal _CompanyModel_default_instance_;
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_companyModel_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_companyModel_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_companyModel_2eproto = nullptr;

const uint32_t TableStruct_companyModel_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::CompanyModel, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::CompanyModel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::CompanyModel, estyear_),
  PROTOBUF_FIELD_OFFSET(::CompanyModel, juristicaddr_),
  PROTOBUF_FIELD_OFFSET(::CompanyModel, name_),
  PROTOBUF_FIELD_OFFSET(::CompanyModel, sortofactivity_),
  PROTOBUF_FIELD_OFFSET(::CompanyModel, exteconomactivity_),
  3,
  0,
  1,
  2,
  4,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, -1, sizeof(::CompanyModel)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_CompanyModel_default_instance_),
};

const char descriptor_table_protodef_companyModel_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022companyModel.proto\"v\n\014CompanyModel\022\017\n\007"
  "estYear\030\001 \002(\005\022\024\n\014juristicAddr\030\002 \002(\t\022\014\n\004n"
  "ame\030\003 \002(\t\022\026\n\016sortOfActivity\030\004 \001(\t\022\031\n\021ext"
  "EconomActivity\030\005 \001(\010"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_companyModel_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_companyModel_2eproto = {
  false, false, 140, descriptor_table_protodef_companyModel_2eproto, "companyModel.proto", 
  &descriptor_table_companyModel_2eproto_once, nullptr, 0, 1,
  schemas, file_default_instances, TableStruct_companyModel_2eproto::offsets,
  file_level_metadata_companyModel_2eproto, file_level_enum_descriptors_companyModel_2eproto, file_level_service_descriptors_companyModel_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_companyModel_2eproto_getter() {
  return &descriptor_table_companyModel_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_companyModel_2eproto(&descriptor_table_companyModel_2eproto);

// ===================================================================

class CompanyModel::_Internal {
 public:
  using HasBits = decltype(std::declval<CompanyModel>()._has_bits_);
  static void set_has_estyear(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_juristicaddr(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_sortofactivity(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static void set_has_exteconomactivity(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x0000000b) ^ 0x0000000b) != 0;
  }
};

CompanyModel::CompanyModel(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:CompanyModel)
}
CompanyModel::CompanyModel(const CompanyModel& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  juristicaddr_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    juristicaddr_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_juristicaddr()) {
    juristicaddr_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_juristicaddr(), 
      GetArenaForAllocation());
  }
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_name()) {
    name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_name(), 
      GetArenaForAllocation());
  }
  sortofactivity_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    sortofactivity_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_sortofactivity()) {
    sortofactivity_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sortofactivity(), 
      GetArenaForAllocation());
  }
  ::memcpy(&estyear_, &from.estyear_,
    static_cast<size_t>(reinterpret_cast<char*>(&exteconomactivity_) -
    reinterpret_cast<char*>(&estyear_)) + sizeof(exteconomactivity_));
  // @@protoc_insertion_point(copy_constructor:CompanyModel)
}

inline void CompanyModel::SharedCtor() {
juristicaddr_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  juristicaddr_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
sortofactivity_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  sortofactivity_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&estyear_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&exteconomactivity_) -
    reinterpret_cast<char*>(&estyear_)) + sizeof(exteconomactivity_));
}

CompanyModel::~CompanyModel() {
  // @@protoc_insertion_point(destructor:CompanyModel)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void CompanyModel::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  juristicaddr_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  sortofactivity_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CompanyModel::ArenaDtor(void* object) {
  CompanyModel* _this = reinterpret_cast< CompanyModel* >(object);
  (void)_this;
}
void CompanyModel::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CompanyModel::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void CompanyModel::Clear() {
// @@protoc_insertion_point(message_clear_start:CompanyModel)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      juristicaddr_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      name_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      sortofactivity_.ClearNonDefaultToEmpty();
    }
  }
  if (cached_has_bits & 0x00000018u) {
    ::memset(&estyear_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&exteconomactivity_) -
        reinterpret_cast<char*>(&estyear_)) + sizeof(exteconomactivity_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* CompanyModel::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required int32 estYear = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _Internal::set_has_estyear(&has_bits);
          estyear_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string juristicAddr = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_juristicaddr();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "CompanyModel.juristicAddr");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string name = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "CompanyModel.name");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional string sortOfActivity = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_sortofactivity();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "CompanyModel.sortOfActivity");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // optional bool extEconomActivity = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _Internal::set_has_exteconomactivity(&has_bits);
          exteconomactivity_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* CompanyModel::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:CompanyModel)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 estYear = 1;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_estyear(), target);
  }

  // required string juristicAddr = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_juristicaddr().data(), static_cast<int>(this->_internal_juristicaddr().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "CompanyModel.juristicAddr");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_juristicaddr(), target);
  }

  // required string name = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "CompanyModel.name");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_name(), target);
  }

  // optional string sortOfActivity = 4;
  if (cached_has_bits & 0x00000004u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_sortofactivity().data(), static_cast<int>(this->_internal_sortofactivity().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "CompanyModel.sortOfActivity");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_sortofactivity(), target);
  }

  // optional bool extEconomActivity = 5;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(5, this->_internal_exteconomactivity(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CompanyModel)
  return target;
}

size_t CompanyModel::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:CompanyModel)
  size_t total_size = 0;

  if (_internal_has_juristicaddr()) {
    // required string juristicAddr = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_juristicaddr());
  }

  if (_internal_has_name()) {
    // required string name = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  if (_internal_has_estyear()) {
    // required int32 estYear = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_estyear());
  }

  return total_size;
}
size_t CompanyModel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CompanyModel)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x0000000b) ^ 0x0000000b) == 0) {  // All required fields are present.
    // required string juristicAddr = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_juristicaddr());

    // required string name = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());

    // required int32 estYear = 1;
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_estyear());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional string sortOfActivity = 4;
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000004u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sortofactivity());
  }

  // optional bool extEconomActivity = 5;
  if (cached_has_bits & 0x00000010u) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData CompanyModel::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    CompanyModel::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*CompanyModel::GetClassData() const { return &_class_data_; }

void CompanyModel::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<CompanyModel *>(to)->MergeFrom(
      static_cast<const CompanyModel &>(from));
}


void CompanyModel::MergeFrom(const CompanyModel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CompanyModel)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_juristicaddr(from._internal_juristicaddr());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_name(from._internal_name());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_set_sortofactivity(from._internal_sortofactivity());
    }
    if (cached_has_bits & 0x00000008u) {
      estyear_ = from.estyear_;
    }
    if (cached_has_bits & 0x00000010u) {
      exteconomactivity_ = from.exteconomactivity_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void CompanyModel::CopyFrom(const CompanyModel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CompanyModel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CompanyModel::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void CompanyModel::InternalSwap(CompanyModel* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &juristicaddr_, lhs_arena,
      &other->juristicaddr_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &name_, lhs_arena,
      &other->name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &sortofactivity_, lhs_arena,
      &other->sortofactivity_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(CompanyModel, exteconomactivity_)
      + sizeof(CompanyModel::exteconomactivity_)
      - PROTOBUF_FIELD_OFFSET(CompanyModel, estyear_)>(
          reinterpret_cast<char*>(&estyear_),
          reinterpret_cast<char*>(&other->estyear_));
}

::PROTOBUF_NAMESPACE_ID::Metadata CompanyModel::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_companyModel_2eproto_getter, &descriptor_table_companyModel_2eproto_once,
      file_level_metadata_companyModel_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::CompanyModel* Arena::CreateMaybeMessage< ::CompanyModel >(Arena* arena) {
  return Arena::CreateMessageInternal< ::CompanyModel >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
