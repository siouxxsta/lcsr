#Requires -Version 7.6
$lang_directory = '../src/languages'

foreach ($lang in 'american', 'french', 'german', 'italian', 'spanish') {
  & .\gxt_compiler\gxt.exe -i "$lang_directory/$lang.txt" -o "../assets/game_lcsr/text/$lang.GXT" -t "tables/vc_sa_table.txt"
}