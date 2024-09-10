#include <tgbot/tgbot.h>
#include <iostream>

int main() {
    TgBot::Bot bot("YOUR_BOT_TOKEN_HERE");

    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hello! Welcome to my bot.");
    });

    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
        if (message->text == "/start") return; // Ignore "/start" command
        bot.getApi().sendMessage(message->chat->id, "You said: " + message->text);
    });

    try {
        std::cout << "Bot is running..." << std::endl;
        TgBot::TgLongPoll longPoll(bot);
        while (true) {
            longPoll.start();
        }
    } catch (TgBot::TgException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
