import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# Email details
fromaddr = "saife.tkd@gmail.com"
toaddr = "saife.tkd@gmail.com"
subject = "Email with Attachment"
body = "Please find attached file"
password = "Temporary@1337"

# Create a multipart message
msg = MIMEMultipart()

# Add the email details to the message
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = subject

# Add the body of the email to the message
msg.attach(MIMEText(body, 'plain'))

# Attach the file to the message
filename = "file.txt"
attachment = open("/Users/skasmi/Desktop/Event-April-2023/ex12/file.txt", "rb")

part = MIMEBase('application', 'octet-stream')
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition', "attachment; filename= %s" % filename)

msg.attach(part)

# Use SMTP to send the message
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, password)
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)
server.quit()

print("Email sent successfully!")
