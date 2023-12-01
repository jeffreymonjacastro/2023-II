import boto3
import uuid
import os
import time

def lambda_handler(event, context):
    # Entrada (json)
    print(event)

    nombre_tabla = os.environ["TABLE_NAME"]
    tenant_id = event['body']['tenant_id']
    codigo_alumno = event['body']['codigo_alumno']
    nombre_alumno = event['body']['nombre_alumno']
    texto = event['body']['texto']
    fecha = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    # Proceso   
    uuidv4 = str(uuid.uuid4())
    comentario = {
        'tenant_id': tenant_id,
        'uuid': uuidv4,
        'detalle': {
            'codigo_alumno': codigo_alumno,
            'nombre_alumno': nombre_alumno,
            'texto': texto,
            'fecha': fecha
        }
    }

    dynamodb = boto3.resource('dynamodb')
    table = dynamodb.Table(nombre_tabla)
    response = table.put_item(Item=comentario)
    # Salida (json)
    print(comentario)
    return {
        'statusCode': 200,
        'comentario': comentario,
        'response': response
    }
