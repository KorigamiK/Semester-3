<?php

// * Use this command to generate a markdown file
// echo "korigamik\n" | php gh-projects.php > test.md

function getJsonData(string $url)
{
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.157 Safari/537.36");
    $result = curl_exec($curl);
    curl_close($curl);
    return json_decode($result, true);
}

$username = readline("Enter the username: ");
$data = getJsonData("https://api.github.com/users/$username/repos?per_page=100");

$table = "| Project | Description | Repo |\n| --- | --- | --- |\n";

foreach ($data as $key => $value) {
    if (!$value['fork']) {
        $table .= "| [" . $value['name'] . "](" . $value['homepage'] . ") | " . $value['description'] . " | [" . $value['full_name'] . "](" . $value['html_url'] . ") |\n";
    }
};

echo $table;
