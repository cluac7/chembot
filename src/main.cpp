#include <dpp/dpp.h>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <string>

const std::string BOT_TOKEN = std::getenv("BOT_TOKEN");

std::unordered_multimap<std::string, std::vector<std::string>> tasks;


int main() {    
    dpp::cluster bot(BOT_TOKEN);

    bot.on_log(dpp::utility::cout_logger());
    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {

            dpp::slashcommand add_task("addtask", "Add a new task reminder", bot.me.id);
            add_task.add_option(dpp::command_option(dpp::co_string, "name", "Name of the task (e.g. learnable: 3.3 Rates of Reaction)", true));
            add_task.add_option(dpp::command_option(dpp::co_string, "date", 
                        "Due date in ISO8601 (2024-06-04 is the 4th June 2024)", true));
            add_task.add_option(dpp::command_option(dpp::co_string, "link", "The link to the task (optional)", false));

            bot.global_command_create(add_task);
        }
    });

    bot.start(true);

    return 0;
}
