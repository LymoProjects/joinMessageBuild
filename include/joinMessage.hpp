#pragma once

#include <string>
#include <unordered_map>
#include <mutex>

namespace lymoProjects__ {
    class __declspec(dllimport) joinMessage {
        std::unordered_map<std::string, std::string> idToMsg;
        std::mutex mutable mut;

        // * Destructor will call this function to save all [id : msg] to local.
        // * Path for local is plugins/.join_message/id_msg.json.
        auto saveToLocal() const -> void;

        // * Constructor will call this function to reload all [id : msg] from local.
        // * Path for local is plugins/.join_message/id_msg.json.
        // * When reloaded, the plugin will run and no longer require id_msg.json.
        auto loadFromLocal() -> void;

        // * Inside, there will be a call to loadFromLocal().
        explicit joinMessage();
    
    public:
    
        // * Inside, there will be a call to saveToLocal().
        ~joinMessage();

        joinMessage(joinMessage const &) = delete;
        auto operator=(joinMessage const &) -> joinMessage & = delete;

        // * Get the only joinMessage object in the entire program life time.
        static 
        auto ref() -> joinMessage &;

        // * thread-safe function.
        // * Get a boolean value for whether there is a join message for the id. 
        auto has(std::string const & id) const -> bool;

        // * thread-safe function.
        // * Set join message with msg for the player who has this id.
        auto set(std::string id, std::string msg) -> void;

        // * thread-safe function.
        // * Get join message for the id.
        // * if this id does not have a join message, function will return ""(empty string),
        // * so you do not need to call has(std::string) before you call this function.
        auto get(std::string id) const -> std::string;

        // * thread-safe function.
        // * Remove join message for the id.
        auto erase(std::string id) -> void;
    };
} // namespace lymoProjects__