#pragma once

#include <string>
#include <unordered_map>
#include <mutex>

namespace lymoProjects__ {
    class joinMessage {
        std::unordered_map<std::string, std::string> idToMsg;
        std::mutex mutable mut;

        // * Destructor will call this function to save all [id : msg] to local.
        auto saveToLocal() const -> void;

        // * Constructor will call this function to reload all [id : msg] from local.
        auto loadFromLocal() -> void;

        explicit joinMessage();
    
    public:
        ~joinMessage();

        joinMessage(joinMessage const &) = delete;
        auto operator=(joinMessage const &) -> joinMessage & = delete;

        // * Get the only joinMessage object in the entire program life time.
        // * All public member functions are thread-safe.
        static 
        auto ref() -> joinMessage &;

        // * Get a boolean value for whether there is a join message for the id. 
        auto has(std::string const & id) const -> bool;

        // * Set join message with msg for the player who has this id.
        auto set(std::string id, std::string msg) -> void;

        // * Get join message for the id.
        auto get(std::string id) const -> std::string;

        // * Remove join message for the id.
        auto erase(std::string id) -> void;
    };
} // namespace lymoProjects__