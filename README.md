# chembot
A discord bot for my chemistry class to stop forgetting homework

## Build
```bash
cd build
cmake ..
```
## Usage
Create a discord bot at [discord developer console](https://discord.com/developers/applications) with the permissions:
-   Send Messages
-   Read Message History
-   Manage Messages
-   Slash Commands

Then run the bot with your discord bot token as an env variable
```bash
BOT_TOKEN=[your token] build/chemistry-bot
```
