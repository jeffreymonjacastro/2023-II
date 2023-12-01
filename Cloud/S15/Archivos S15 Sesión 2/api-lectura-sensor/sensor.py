import boto3
import uuid
import os
import time

def lambda_handler(event, context):
    # Entrada (json)
    print(event)

    nombre_tabla = os.environ["TABLE_NAME"]
    id_sensor = event['body']['id_sensor']
    unidad_medida = event['body']['unidad_medida']
    valor_medido = event['body']['valor_medido']
    fecha_hora = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    # Proceso   
    uuidv4 = str(uuid.uuid4())
    medicion = {
        'id_sensor': id_sensor,
        'uuid': uuidv4,
        'detalles': {
            'unidad_medida': unidad_medida,
            'valor_medido': valor_medido,
            'fecha_hora': fecha_hora
        }
    }

    dynamodb = boto3.resource('dynamodb')
    table = dynamodb.Table(nombre_tabla)
    response = table.put_item(Item=medicion)
    # Salida (json)
    print(medicion)
    return {
        'statusCode': 200,
        'medicion': medicion,
        'response': response
    }
