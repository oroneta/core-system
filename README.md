Arrancar docker con el comando:
```bash
cd docker
docker-compose up -d --build --force-recreate
```

-d para que se ejecute en segundo plano
--build para que se construya la imagen
--force-recreate para que se vuelva a crear el contenedor