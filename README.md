<h1>Adventure RPG Game</h1>

<h2>Overview</h2>
<p>This project is a simple text-based RPG game written in C++. Players navigate through a fantasy world, encountering enemies and making choices to progress in the game.</p>

<h2>Contributors</h2>
    <ul>
        <li>arezyh.s https://github.com/arezyhs </li>
        <li>shylniac https://github.com/shylniac </li>
    </ul>

<h2>Features</h2>
    <ul>
        <li><strong>Player Class:</strong> The game includes a <code>Player</code> class with attributes such as name, level, experience, health, attack, coins, and defense.</li>
        <li><strong>Enemy Classes:</strong> Various enemy classes, such as <code>GoblinEnemy</code>, <code>WizardEnemy</code>, <code>DarkKnightEnemy</code>, <code>GiantEnemy</code>, and <code>FinalBossEnemy</code>, each with unique characteristics.</li>
        <li><strong>Combat System:</strong> Players engage in turn-based combat with enemies, choosing to attack or run away. Combat outcomes impact player stats and progression.</li>
        <li><strong>Exploration:</strong> Players can explore the game world, encountering random events like finding coins or facing enemies. Level 10 introduces a final boss encounter.</li>
        <li><strong>Healing:</strong> Players can choose to heal by spending coins, replenishing health during their journey.</li>
        <li><strong>Save and Load:</strong> The game supports saving and loading player progress using a text file (<code>player_progress.txt</code>).</li>
        <li><strong>Class Selection:</strong> Players can choose their character class at the beginning, affecting starting stats.</li>
    </ul>

<h2>How to Play</h2>
    <ol>
        <li>Enter your character's name.</li>
        <li>Choose a character class: Warrior, Archer, or Knight.</li>
        <li>Embark on an adventure, exploring the world, battling enemies, and leveling up.</li>
        <li>Use the options to explore, heal, save, load, or exit the game.</li>
    </ol>

<h2>Character Classes</h2>
    <ul>
        <li><strong>Warrior:</strong>
            <ul>
                <li>Health: 100</li>
                <li>Attack: 20</li>
                <li>Defense: 5</li>
            </ul>
        </li>
        <li><strong>Archer:</strong>
            <ul>
                <li>Health: 75</li>
                <li>Attack: 20</li>
                <li>Defense: 20</li>
            </ul>
        </li>
        <li><strong>Knight:</strong>
            <ul>
                <li>Health: 150</li>
                <li>Attack: 25</li>
                <li>Defense: 10</li>
            </ul>
        </li>
    </ul>

<h2>Cheat Code (for testing)</h2>
    <p>Press <code>9</code> when choosing a character class to activate cheat mode, setting your character to level 10 with enhanced stats.</p>

<h2>Dependencies</h2>
    <ul>
        <li>C++ Standard Library</li>
    </ul>

<h2>How to Compile and Run</h2>
    <ol>
        <li>Make sure you have a C++ compiler installed.</li>
        <li>Compile the source code.
            <pre>
                <code>g++ -o adventure_rpg adventure_rpg.cpp</code>
            </pre>
        </li>
        <li>Run the executable.
            <pre>
                <code>./adventure_rpg</code>
            </pre>
        </li>
    </ol>

<h2>Acknowledgments</h2>
    <p>Thank you for playing the Adventure RPG game! Have fun exploring the fantasy world and overcoming challenges!</p>

</body>

</html>
