#pragma once

#include "Byte.h"

#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <vector>
#include <string>

using namespace godot;

namespace io {
    class ByteArray {
    private:
        std::vector<Byte*> data;

    public:
        ByteArray() = default;

        ByteArray(const std::vector<Byte*>& data) : data(data) {}

        ByteArray(const std::vector<uint8_t>& data) {
            for (const auto& byte : data) {
                this->data.emplace_back(new Byte(byte));
            }
        }

        ByteArray(const PackedByteArray& packed_data) {
            for (int i = 0; i < packed_data.size(); ++i) {
                this->data.emplace_back(new Byte(packed_data[i]));
            }
        }

        int size() const {
            return (int)data.size();
        }

        Byte* get(int index) const {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            return data[index];
        }

        void set(int index, Byte* byte) {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            data[index] = byte;
        }

        void resize(int new_size) {
            data.resize(static_cast<size_t>(new_size));
        }

        void append(Byte* byte) {
            data.push_back(byte);
        }

        void insert(int index, Byte* byte) {
            if (index < 0 || index > static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            data.insert(data.begin() + index, byte);
        }

        void removeAt(int index) {
            if (index < 0 || index >= static_cast<int>(data.size())) {
                UtilityFunctions::printerr("Index out of range");
            }
            data.erase(data.begin() + index);
        }

        void clear() {
            data.clear();
        }

        std::string toString() const {
            std::string result;
            for (const auto& byte : data) {
                int i = byte->getInt();
                result += std::to_string(i) + " ";
            }
            return result;
        }

        std::vector<uint8_t> toVector() const {
            std::vector<uint8_t> result;
            for (const auto& byte : data) {
                result.push_back(byte->getData());
            }
            return result;
        }

        PackedByteArray toPackedByteArray() const {
            PackedByteArray packed_data;
            for (const auto& byte : data) {
                packed_data.append(byte->getData());
            }
            return packed_data;
        }
    };
}
