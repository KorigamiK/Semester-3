# DBMS

You can use the following command to start the Postgres server in docker:

```bash
docker run --name postgres-test --rm -e POSTGRES_USER=postgres -e POSTGRES_PASSWORD=test1234 -p 5432:5432 -v "$(pwd)/sql:/home/sql" postgres:latest
```

You can use the following command to write SQL queries in interactive mode:

```bash
docker exec -it postgres-test bash
psql -U postgres
```

Now you can use the following command to create the database:

```sql
CREATE DATABASE practicals;
\connect practicals;
```

Use the following to run the SQL scripts:

```bash
psql -U postgres -d practicals -a -f /home/sql/1.sql
```

Or in interactive mode:

```sql
\i /home/sql/1.sql
```