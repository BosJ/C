if [ ! -f passwords.txt.enc ]; then
    # first use
    vi UNSAFE.txt
else
    # backup
    mkdir -p backup
    timestamp=$(date +%s)
    cp *.enc backup/passwords.$timestamp.txt.enc 
    # decrypt
    openssl enc -aes-256-cbc -d -in passwords.txt.enc -out UNSAFE.txt
    # edit
    vi UNSAFE.txt
fi

# encrypt
openssl enc -aes-256-cbc -salt -in UNSAFE.txt -out passwords.txt.enc
rm *.txt

#todo: secure remove and wipe vi buffer
